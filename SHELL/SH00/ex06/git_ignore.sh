#!/bin/sh
git status --ignored -s | grep '!! ' | sed 's/!! //g'
