/**
 * ADVi3++ Firmware For Wanhao Duplicator i3 Plus (based on Marlin 2)
 *
 * Copyright (C) 2017-2021 Sebastien Andrivet [https://github.com/andrivet/]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#if ENABLED(ADVi3PP_X_TWIST)

#include "../../lcd/extui/ui_api.h"

namespace ADVi3pp
{
    const float DEFAULT_X_TWIST_A = 100.0;
    const float DEFAULT_X_TWIST_B = 0.0;

    struct x_twist_factors_t
    {
        float a_ = DEFAULT_X_TWIST_A;
        float b_ = DEFAULT_X_TWIST_B;
    };

    extern x_twist_factors_t x_twist_factors;

    inline float twist(float x) { return x_twist_factors.b_ * (x - X_BED_SIZE / 2) / x_twist_factors.a_; }
    inline void x_twist(xyze_pos_t &pos)   { pos.z += twist(pos.x); }
    inline void x_untwist(xyze_pos_t &pos) { pos.z -= twist(pos.x); }
}

#endif