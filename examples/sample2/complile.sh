#!/bin/bash

ecpg sample2.pgc
gcc sample2.c -o sample2 -I$(pg_config \
--includedir) -L$(pg_config --libdir) -lecpg

