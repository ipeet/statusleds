/******************************************************************************
 * meminfo.h
 * Copyright 2010 Iain Peet
 *
 * Obtains some basic memory utilization information from /proc/meminfo
 ******************************************************************************
 * This program is distributed under the of the GNU Lesser Public License. 
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/

#ifndef MEMINFO_H_
#define MEMINFO_H_

#include <iostream>

class Meminfo {
public:
    long m_total;
    long m_free;
    long m_buffers;
    long m_cached;

public:
    // Read current memory utilization data from /proc/meminfo 
    int update();

    /* Fraction of memory currently in use.  
     * NB: We don't consider cache and buffer memory 'used' */
    double getUtilization();

private:
    // Read from a stream until a newline is consumed
    void clearLine(std::istream& stream);
};

#endif // MEMINFO_H_

