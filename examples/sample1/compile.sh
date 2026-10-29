#!/bin/bash

gcc sample1.c -o sample1 -I$(pg_config \
--includedir) -L$(pg_config --libdir) -lpq
