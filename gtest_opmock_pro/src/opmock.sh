#!/bin/bash

BLUE=$(tput setaf 4)
RESET=$(tput sgr0)

INPUT_FILE=""
OUTPUT_PATH=""
HEADER_PREFIX=""
HEADER=""
OUTPUT_BASE_FILENAME=""
USE_CPP="yes"
USE_RECURSE="no"
NO_MOCK="no"
SKIP_FUNCT=""
KEEP_ONLY=""
USE_IMPL="no"

# analyze parameters
NB_PARAMS=$#
MAX_PARAMS=$(($NB_PARAMS - 1))

for (( i = 0 ; i < $MAX_PARAMS ; i++ ))
do
    oneParam=$1
    if [ "$oneParam" = "--input-file" ]; then
        shift
        INPUT_FILE=$1
        shift
    elif [ "$oneParam" = "--output-path" ]; then
        shift
        OUTPUT_PATH=$1
        shift
    elif [ "$oneParam" = "--header-prefix" ]; then
        shift
        HEADER_PREFIX="--header-prefix ${1}"
        shift
    elif [ "$oneParam" = "--use-cpp" ]; then
        shift
        USE_CPP=$1
        shift
    elif [ "$oneParam" = "--no-mock" ]; then
        shift
        NO_MOCK=$1
        shift
    elif [ "$oneParam" = "--skip-funct" ]; then
        shift
        SKIP_FUNCT="--skip-funct ${1}"
        shift
    elif [ "$oneParam" = "--keep-only" ]; then
        shift
        KEEP_ONLY="--keep-only ${1}"
        shift
    elif [ "$oneParam" = "--use-impl" ]; then
        shift
        USE_IMPL=$1
        shift
    elif [ "$oneParam" = "--opmock_jar" ]; then
        shift
        OPMOCK_JAR=$1
        shift
    elif [ "$oneParam" = "--swig" ]; then
        shift
        SWIG=$1
        shift
    elif [ "$oneParam" = "--output-filename-base" ]; then
        shift
        OUTPUT_BASE_FILENAME=$1
        shift
    fi
done


HEADER=$(basename $INPUT_FILE)

if [ "$OUTPUT_BASE_FILENAME" = "" ]; then
    OUTPUT_BASE_FILENAME=${HEADER%.*}
fi

if [ "$USE_CPP" = "yes" ]; then
    SWIG_CPP="-c++"
fi

if [ _$OPMOCK_JAR = _ ]; then
    OPMOCK_JAR=/home/jacob/work/tools/opmock-code/trunk/opmock1/scripts/opmock.jar
fi

echo $SWIG_CPP
SWIG=/usr/local/bin/swig
swig_cmd="$SWIG -includeall -ignoremissing -module module $SWIG_CPP \
    -xmlout ${OUTPUT_BASE_FILENAME}.xml $INPUT_FILE"

#test dump
echo "OUTPUT_BASE_FILENAME"
echo $OUTPUT_BASE_FILENAME
#end test

echo "${BLUE}Calling SWIG to generate AST...${RESET}"
echo $swig_cmd
$swig_cmd
echo "${BLUE}Done${RESET}"

echo "${BLUE}Calling Opmock to generate the mocks...${RESET}"
java_cmd="java -jar $OPMOCK_JAR --input-file ${OUTPUT_BASE_FILENAME}.xml --output-path $OUTPUT_PATH \
    --header $HEADER --use-cpp $USE_CPP $HEADER_PREFIX --no-mock $NO_MOCK $SKIP_FUNCT $KEEP_ONLY \
    --use-impl $USE_IMPL"
echo $java_cmd
$java_cmd
echo "${BLUE}Done${RESET}"

#clean up
rm ${OUTPUT_BASE_FILENAME}.xml
rm -fr *.cxx
