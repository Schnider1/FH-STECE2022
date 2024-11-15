#pragma once

#include "sysfs-file.h"
#include <filesystem>


class SysFSPWMPin
{
public:
    SysFSPWMPin(const std::filesystem::path& pindir)
    : _period_file(pindir / "period"),
      _duty_cycle_file(pindir / "duty_cycle")
    {}

    uint64_t period()
    {
        return _period_file.read_uint64();
    }

    uint64_t duty_cycle()
    {
        return _duty_cycle_file.read_uint64();
    }

    void set_duty_cycle(uint64_t i)
    {
        if (i > period())
        {
            throw std::invalid_argument("Duty cycle is bigger than period");
        }
        else
        {
            _duty_cycle_file.write_uint64(i);
        }
    }

private:
    SysFSFile _period_file;
    SysFSFile _duty_cycle_file;
};
