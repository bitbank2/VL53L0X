//
// Time of Flight sensor test program
//
// Copyright (c) 2017 Larry Bank
// email: bitbank@pobox.com
// Project started 7/29/2017
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
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <tof.h> // time of flight sensor library

int main(int argc, char *argv[])
{
int i;
int iDistance;
int model, revision;

	// For Raspberry Pi's, the I2C channel is usually 1
	// For other boards (e.g. OrangePi) it's 0
	i = tofInit(0, 0x29, 1); // set long range mode (up to 2m)
	if (i != 1)
	{
		return -1; // problem - quit
	}
	printf("VL53L0X device successfully opened.\n");
	i = tofGetModel(&model, &revision);
	printf("Model ID - %d\n", model);
	printf("Revision ID - %d\n", revision);

	for (i=0; i<1200; i++) // read values 20 times a second for 1 minute
	{
		iDistance = tofReadDistance();
		if (iDistance < 4096) // valid range?
			printf("Distance = %dmm\n", iDistance);
		usleep(50000); // 50ms
	}

return 0;
} /* main() */
