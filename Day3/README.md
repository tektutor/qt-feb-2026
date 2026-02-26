# Day 3

## Info - Troubleshooting qDebug() outputs not visible in Qt Creator or Command-line
```
export QT_LOGGING_RULES="default.debug=true"
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./QtSignalWithQMLSlotWithConnectionFromMain
```
