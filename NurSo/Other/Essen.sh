#!/bin/bash

html="www.stw.uni-heidelberg.de/de/speiseplan_neu"
beautify=$(w3m -T text/html "$html"|cat)
today=$(date +%A)
tomorrow=$(date --date="tomorrow" +%A)
regex="$today"'(.|\n)*?('"$tomorrow"')'
echo "$beautify" | grep -Pzo "$regex" | head -24
