#!/bin/sh

PREFIX="%%PREFIX%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILE="%%JAR_FILE%%"

${JAVAVM} -jar ${PREFIX}/${JAR_DIR}/${JAR_FILE} "${@}"
