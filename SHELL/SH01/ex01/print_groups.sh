#!/bin/sh
id -nG $FT_USER | tr ' ' ',' | tr -d '\n'
