//
// Created by Gahwon on 8/18/2019.
//

#include <chrono>
#include <sstream>
#include <iostream>
#include "calculator.h"

static GtkLabel *bpm_label = nullptr;
static GtkLabel *taps_label = nullptr;

static double sum_bpm = 0.0;
static double prev_bpm = 0.0;
static std::chrono::time_point prev_tap = std::chrono::high_resolution_clock::now();

static uint32_t num_taps = 0;
static uint32_t num_ignored_taps = 0;
static bool is_prev_tap_valid = false;

void bpm::init(GtkLabel *bpm, GtkLabel *taps) {
    bpm_label = bpm;
    taps_label = taps;
    reset();
}

void update_labels() {
    if ((num_taps - num_ignored_taps) == 0)
        gtk_label_set_text(bpm_label, "0");
    else
        gtk_label_set_text(bpm_label, std::to_string(bpm::get_bpm()).c_str());

    std::stringstream ss;
    ss << "Taps: " << num_taps;
    gtk_label_set_text(taps_label, ss.str().c_str());
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-incorrect-roundings"
int bpm::get_bpm() {
    return (int) ((sum_bpm / (num_taps - num_ignored_taps)) + 0.5);
}
#pragma clang diagnostic pop

void bpm::tap() {
    auto curr_tap = std::chrono::high_resolution_clock::now();
    if (is_prev_tap_valid) {
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(curr_tap - prev_tap).count();
        constexpr int64_t min_in_ms = 60000000;
        prev_bpm = (double) min_in_ms / microseconds;
        sum_bpm += prev_bpm;
    } else {
        is_prev_tap_valid = true;
        ++num_ignored_taps;
    }
    prev_tap = curr_tap;
    ++num_taps;

    update_labels();
}

void bpm::undo() {
    if (num_taps < 2) {
        reset();
    } else {
        sum_bpm -= prev_bpm;
        --num_taps;
        is_prev_tap_valid = false;
        update_labels();
    }
}

void bpm::reset() {
    sum_bpm = 0.0;
    is_prev_tap_valid = false;
    num_taps = 0;
    num_ignored_taps = 0;
    update_labels();
}
