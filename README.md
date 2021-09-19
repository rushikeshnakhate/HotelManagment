# HotelManagment

Problem Statement: An owner of a boutique hotel asked you to develop a program to help him assign available rooms to his guests. Your program must find the nearest available room measured by the route taken from the entrance to the room (diagram provided in task ) and assign it to the guest


Development Process : 

1. Devided Problem into bunch of small Tasks All can be found here https://github.com/rushikeshnakhate/HotelManagment/issues?q=
2. TDD Approch - Added test for each path and then Added implelemntation .
3. Branchs information Please find the list of branches , PR raise during the development process -https://github.com/rushikeshnakhate/HotelManagment/branches


Please follow below steps to run the application

 
4. clone the repo 
**git clone https://github.com/rushikeshnakhate/HotelManagment.git**
```
Cloning into 'HotelManagment'...
remote: Enumerating objects: 326, done.
remote: Counting objects: 100% (326/326), done.
remote: Compressing objects: 100% (231/231), done.
remote: Total 326 (delta 91), reused 305 (delta 82), pack-reused 0
Receiving objects: 100% (326/326), 938.48 KiB | 2.66 MiB/s, done.
Resolving deltas: 100% (91/91), done.

```


5. Compilation 
rushi@RUSHI-PC:~$ cd HotelManagment/
rushi@RUSHI-PC:~/HotelManagment$ /usr/local/bin/cmake CMakeLists.txt

```
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Python: /usr/bin/python3.6 (found version "3.6.9") found components:  Interpreter
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Configuring done
-- Generating done
-- Build files have been written to: /home/rushi/HotelManagment
```

rushi@RUSHI-PC:~/HotelManagment$ make
```
Scanning dependencies of target gtest
[  5%] Building CXX object src/test/libs/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 10%] Linking CXX static library ../../../../lib/libgtest.a
[ 10%] Built target gtest
Scanning dependencies of target gtest_main
[ 15%] Building CXX object src/test/libs/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 20%] Linking CXX static library ../../../../lib/libgtest_main.a
[ 20%] Built target gtest_main
Scanning dependencies of target HotelManagementTest
[ 25%] Building CXX object src/test/CMakeFiles/HotelManagementTest.dir/TestMain.cpp.o
[ 30%] Building CXX object src/test/CMakeFiles/HotelManagementTest.dir/TestStateMachine.cpp.o
[ 35%] Building CXX object src/test/CMakeFiles/HotelManagementTest.dir/TestDatabase.cpp.o
[ 40%] Building CXX object src/test/CMakeFiles/HotelManagementTest.dir/__/main/Database.cpp.o
[ 45%] Building CXX object src/test/CMakeFiles/HotelManagementTest.dir/__/main/Reception.cpp.o
[ 50%] Building CXX object src/test/CMakeFiles/HotelManagementTest.dir/__/main/StateMachine.cpp.o
[ 55%] Linking CXX executable HotelManagementTest
[ 55%] Built target HotelManagementTest
Scanning dependencies of target gmock
[ 60%] Building CXX object src/test/libs/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 65%] Linking CXX static library ../../../../lib/libgmock.a
[ 65%] Built target gmock
Scanning dependencies of target gmock_main
[ 70%] Building CXX object src/test/libs/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 75%] Linking CXX static library ../../../../lib/libgmock_main.a
[ 75%] Built target gmock_main
Scanning dependencies of target HotelManagementMain
[ 80%] Building CXX object src/main/CMakeFiles/HotelManagementMain.dir/Database.cpp.o
[ 85%] Building CXX object src/main/CMakeFiles/HotelManagementMain.dir/Main.cpp.o
[ 90%] Building CXX object src/main/CMakeFiles/HotelManagementMain.dir/Reception.cpp.o
[ 95%] Building CXX object src/main/CMakeFiles/HotelManagementMain.dir/StateMachine.cpp.o
[100%] Linking CXX executable HotelManagementMain
[100%] Built target HotelManagementMain
rushi@RUSHI-PC:~/HotelManagment$ cd src/test/
rushi@RUSHI-PC:~/HotelManagment/src/test$ ./
CMakeFiles/          HotelManagementTest  libs/
```


5. Run the test 
cd HotelManagment/src/test$ ./HotelManagementTest

```
[==========] Running 9 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from HotelInit
[ RUN      ] HotelInit.when_hotel_created_then_initial_status_is_available
[       OK ] HotelInit.when_hotel_created_then_initial_status_is_available (0 ms)
[----------] 1 test from HotelInit (1 ms total)

[----------] 7 tests from TestStateMachine
[ RUN      ] TestStateMachine.only_available_room_can_booked
CheckIn request is Success, for room ='1A'
[       OK ] TestStateMachine.only_available_room_can_booked (1 ms)
[ RUN      ] TestStateMachine.assigned_available_room_become_occupied
[       OK ] TestStateMachine.assigned_available_room_become_occupied (0 ms)
[ RUN      ] TestStateMachine.checkedout_room_become_vaccant
CheckOut request is Success, for room ='1A'
[       OK ] TestStateMachine.checkedout_room_become_vaccant (0 ms)
[ RUN      ] TestStateMachine.vaccant_room_after_cleaning_become_availabe
Cleaning request is Success, for room ='1A'
[       OK ] TestStateMachine.vaccant_room_after_cleaning_become_availabe (1 ms)
[ RUN      ] TestStateMachine.vaccant_room_can_be_repaired
CheckIn request is Success, for room ='1A'
CheckOut request is Success, for room ='1A'
Repairing request is Success, for room ='1A'
[       OK ] TestStateMachine.vaccant_room_can_be_repaired (2 ms)
[ RUN      ] TestStateMachine.once_room_is_repaired_become_vacant
CheckIn request is Success, for room ='1B'
RepairingCompleted request is Success, for room ='1A'
[       OK ] TestStateMachine.once_room_is_repaired_become_vacant (4 ms)
[ RUN      ] TestStateMachine.room_under_repair_can_only_be_vacant
CheckIn request is Success, for room ='1C'
Repairing request is Success, for room ='1A'
[       OK ] TestStateMachine.room_under_repair_can_only_be_vacant (1 ms)
[----------] 7 tests from TestStateMachine (42 ms total)

[----------] 1 test from TestDatabase
[ RUN      ] TestDatabase.validate_room_name_sequence
[       OK ] TestDatabase.validate_room_name_sequence (0 ms)
[----------] 1 test from TestDatabase (11 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 3 test suites ran. (66 ms total)
[  PASSED  ] 9 tests.
```




