//
// Created by Gahwon on 8/18/2019.
//

#include "musicbee.h"
#include <stdexcept>

#ifdef MUSICBEE

#include <unistd.h>
#include <filesystem>
#include <string>
#include <iostream>

static const char *const executable = "ChangeMusicBee.exe";

void bpm::try_set_bpm(int bpm) {
    if (!std::filesystem::exists(executable)) {
        throw std::runtime_error("Could not find executable.");
    }

    std::cout << "Time to musicbee" << std::endl;

    std::stringstream ss;
    ss << executable << " " << bpm;
    if (system(ss.str().c_str()) != 0) {
        throw std::runtime_error("Exception occured while running the executable.");
    }
}

#else

void bpm::try_set_bpm(int bpm) {
    throw std::runtime_error("Only available on Windows.");
}

#endif
