#!/bin/bash
# Be verbose. Exit on any error -
set -e -v
ORIG_DIR=$(pwd)

NAME_VERSION=SDL2-2.0.8
URL_BASE=https://www.libsdl.org/release/

BUILD_DIR="/tmp/${USER}_build_dir"
INSTALL_DIR="${HOME}/localinstall"

echo "Compile and Install ${NAME_VERSION} to ${INSTALL_DIR} ?"
echo "Type y and ENTER to continue"
read ANSWER
[ "${ANSWER}" == "y" ]


[ -d "${BUILD_DIR}" ] || mkdir -m 700 "${BUILD_DIR}"
[ -d "${INSTALL_DIR}" ] || mkdir -p "${INSTALL_DIR}" 

cd "${BUILD_DIR}"
wget -N ${URL_BASE}/${NAME_VERSION}.zip
unzip -quo "${NAME_VERSION}.zip"
rm "${NAME_VERSION}.zip"
cd "${NAME_VERSION}"

./configure --prefix="${INSTALL_DIR}"

make -j
make install

cd "$ORIG_DIR"
rm -rf "${INSTALL_DIR}/${NAME_VERSION}"

echo "SDL include and library files are in ${INSTALL_DIR}"
