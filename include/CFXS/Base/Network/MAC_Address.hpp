// CFXS Framework Base Module <https://github.com/CFXS/CFXS-Base>
// Copyright (C) 2021 - CFXS / Rihards Veips
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// [CFXS] //
#pragma once

#include <array>

namespace CFXS {

    class MAC_Address {
    public:
        constexpr MAC_Address(uint8_t b) : m_Data({b, b, b, b, b, b}) {
        }
        constexpr MAC_Address(const uint8_t data[6]) : m_Data({data[0], data[1], data[2], data[3], data[4], data[5]}) {
        }
        constexpr MAC_Address(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f) : m_Data({a, b, c, d, e, f}) {
        }
        constexpr MAC_Address(const MAC_Address& other) : m_Data(other.m_Data) {
        }

        constexpr uint8_t* GetDataPointer() {
            return m_Data.data();
        }

        constexpr const uint8_t* GetDataPointer() const {
            return m_Data.data();
        }

        inline bool operator==(const MAC_Address& other) const {
            return memcmp(GetDataPointer(), other.GetDataPointer(), 6) == 0;
        }

        inline bool operator!=(const MAC_Address& other) const {
            return !(*this == other);
        }

        inline uint8_t& operator[](uint8_t index) {
            return m_Data[index];
        }

        inline const uint8_t& operator[](uint8_t index) const {
            return m_Data[index];
        }

    private:
        std::array<uint8_t, 6> m_Data;
    };

} // namespace CFXS