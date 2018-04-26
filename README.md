Learning discrite mathematics
=============================

Build
=====
   user@pc:~$ git clone https://github.com/dvetutnev/learn_discrete_math.git
   user@pc:~$ mkdir build-learn_discrete_math
   user@pc:~$ cd build-learn_discrete_math
   user@pc:~/build-learn_discrete_math$ cmake -DCMAKE_BUILD_TYPE=Release ../learn_discrete_math
   user@pc:~/build-learn_discrete_math$ cmake --build .
   user@pc:~/build-learn_discrete_math$ ctest


By default this project used [Conan package manager](http://conan.io). Please install it and add Odant repository:

    user@pc:~$ conan remote add odant-bintray https://api.bintray.com/conan/odant/conan

You maybe use system libraries. In this case disable Conan:

    user@pc:~/build-learn_discrete_math$ cmake -DCMAKE_BUILD_TYPE=Release -DUSE_CONAN=OFF ../learn_discrete_math