#!/bin/bash
num1=${1}
src_Hz=${2}
dst_Hz=${3}

# echo ${num1}

current_dir=$PWD
current_folder=${current_dir}/build
cd ${current_folder}

if [ ${num1} -eq 1 ]
then
    make clean;make;
    echo "num1: ${num1}"
else
    echo "num1: ${num1}"
fi 
echo "src_Hz: ${src_Hz}  dst_Hz: ${dst_Hz}"
./resampler /Users/okrio/learning/AudioData/ref.pcm ../out/out.pcm ${src_Hz} ${dst_Hz}
cd ../
