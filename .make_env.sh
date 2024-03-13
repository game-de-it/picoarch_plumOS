#!/bin/sh

### As of March 11, 2024, picoarch can only be built in a 32bit environment
#
#
# This is a script used when you want to build picoarch manually without using a build system.
# Create an environment variable for cross-build and create a file to "include" in the Makefile.
# example
#
# echo "CROSS_COMPILE = /home/username/plumOS/build.plumOS-RK3566.arm/toolchain/bin/armv8a-libreelec-linux-gnueabi-" > ${PICOARCH_DIR}/.env
# echo "SYSROOT = /home/username/plumOS/build.plumOS-RK3566.arm/toolchain/armv8a-libreelec-linux-gnueabi/sysroot" >> ${PICOARCH_DIR}/.env
# echo "CC = /home/username/plumOS/build.plumOS-RK3566.arm/toolchain/bin/armv8a-libreelec-linux-gnueabi-gcc" >> ${PICOARCH_DIR}/.env
# echo "CXX = /home/username/plumOS/build.plumOS-RK3566.arm/toolchain/bin/armv8a-libreelec-linux-gnueabi-g++" >> ${PICOARCH_DIR}/.env
# echo "AR = /home/username/plumOS/build.plumOS-RK3566.arm/toolchain/bin/armv8a-libreelec-linux-gnueabi-ar" >> ${PICOARCH_DIR}/.env
# echo "LD = /home/username/plumOS/build.plumOS-RK3566.arm/toolchain/bin/armv8a-libreelec-linux-gnueabi-ld" >> ${PICOARCH_DIR}/.env


PICOARCH_DIR=$(cd $(dirname $0) && pwd)
CROSS_COMPILE_PATH=""
SYSROOT_PATH=""
CC_PATH=""
CXX_PATH=""
AR_PATH=""
LD_PATH=""
echo "CROSS_COMPILE = ${CROSS_COMPILE_PATH}" > ${PICOARCH_DIR}/.env
echo "SYSROOT = ${SYSROOT_PATH}" >> ${PICOARCH_DIR}/.env
echo "CC = ${CC_PATH}" >> ${PICOARCH_DIR}/.env
echo "CXX = ${CXX_PATH}" >> ${PICOARCH_DIR}/.env
echo "AR = ${AR_PATH}" >> ${PICOARCH_DIR}/.env
echo "LD = ${LD_PATH}" >> ${PICOARCH_DIR}/.env

