#!/bin/sh
ifconfig | grep -w 'ether' | awk '{print $2}'
