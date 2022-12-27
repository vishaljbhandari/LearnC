#!/bin/bash

CURR_DIR=`pwd`
echo -e "Current Directory $CURR_DIR"
LOG_DIR=/media/sf_VMShare/logs/cspace/
echo -e "Log Directory $LOG_DIR"
CURRENT_TIMESTAMP=`date +'%d%m%Y%H%M%S'`

S_LOG_FILE=$LOG_DIR/stat_analyzer_$CURRENT_TIMESTAMP.log
echo -e "Stat Log File $S_LOG_FILE"

G_LOG_FILE=$LOG_DIR/git_analyzer_$CURRENT_TIMESTAMP.log
echo -e "Git Log File $G_LOG_FILE"

./static_analyzer.sh $1 > $S_LOG_FILE  2>&1

./git_analyzer.sh > $G_LOG_FILE  2>&1
