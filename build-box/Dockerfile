#
# Dockerfile for building C++ project
#
# https://github.com/tatsy/dockerfile/ubuntu/cxx
#
# Edited to be more consistent with Travis-CI build.

# OS image
FROM ubuntu:16.04

# Install
RUN \
  sed -i 's/# \(.*multiverse$\)/\1/g' /etc/apt/sources.list && \
  apt-get update -qq && \
  apt-get upgrade -qq && \
  apt-get install -qq build-essential clang && \
  apt-get install -qq software-properties-common && \
  apt-get install -qq byobu curl git htop man unzip vim wget && \
  apt-get install -qq subversion cmake && \
  rm -rf /var/lib/apt/lists/*

# Set environment variables.
ENV HOME /working

# Define working directory. Share src volume here
WORKDIR /working

# Define default command.
CMD ["bash"]

# Update gcc/g++ to v5
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt-get update -qq
RUN apt-get install -qq gcc-5 g++-5

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 60
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 60
RUN update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-5 60

# Update clang
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-7 main"
RUN apt-get update
RUN apt-get install -qq -y clang-7

# Install LCOV
#RUN git clone https://github.com/linux-test-project/lcov.git
#RUN make -C lcov install
RUN apt-get install -qq -y lcov
RUN apt-get install -qq -y ruby
RUN gem install coveralls-lcov

# Install OpenMP for LLVM
RUN svn co http://llvm.org/svn/llvm-project/openmp/trunk openmp
RUN \
  cd openmp && \
  mkdir build && \
  cd build && \
  cmake .. && \
  make omp && \
  make install && \
  cd -

# Update CMake to v3.12.4
RUN git clone --depth 1 -b v3.12.4 https://github.com/Kitware/CMake.git
RUN \
  cd CMake && \
  mkdir build && \
  cd build && \
  cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr && \
  make -j4 && \
  make install && \
  ldconfig && \
  cd ../.. && \
  cmake --version

# Clean working directory
RUN rm -rf openmp
RUN rm -rf CMake
RUN rm -rf lcov
RUN rm -rf /usr/src/gtest

# Show environments
RUN echo "--- Build Environment ---"
RUN cat /etc/lsb-release
RUN gcc --version | grep gcc
RUN g++ --version | grep g++
RUN lcov --version | grep version
RUN clang --version | grep version
RUN clang++ --version | grep version
RUN cmake --version | grep version
RUN echo "------------------------"