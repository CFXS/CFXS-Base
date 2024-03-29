// ---------------------------------------------------------------------
// CFXS Framework Base Module <https://github.com/CFXS/CFXS-Base>
// Copyright (C) 2022 | CFXS / Rihards Veips
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ---------------------------------------------------------------------
// [CFXS] //
#pragma once

namespace CFXS {

    template<typename T>
    constexpr void SafeCall(T fn) {
        if (fn) {
            fn();
        }
    }

    constexpr auto CreateBitMask(int bits) {
        return (1 << bits) - 1;
    }

} // namespace CFXS

#define CFXS_ENUM_OPERATORS(enumName)                                                                                       \
    constexpr enumName operator|(enumName a, enumName b) {                                                                  \
        return static_cast<enumName>(static_cast<std::underlying_type<enumName>::type>(a) |                                 \
                                     static_cast<std::underlying_type<enumName>::type>(b));                                 \
    }                                                                                                                       \
    constexpr bool operator&(enumName a, enumName b) {                                                                      \
        return static_cast<std::underlying_type<enumName>::type>(a) & static_cast<std::underlying_type<enumName>::type>(b); \
    }
