# Wine FakeSC
A wrapper for the wine `sc` command. It always exits with a status code of 0 (success), allowing some package installers to successfully install under Wine.

## System file restore
After all Windows processes exit (that is, after the `wineserver` process exits), any changes in `C:\windows\system32` may be lost.

So, the replacement of `sc.exe` needs to be done in the Wine's Windows environment (Modifications made in Linux may not be visible in Wine's Windows environment), and a replacement operation may be required before each package installation. 

If you find that the sc.exe replacement that was once done no longer works, Wine is probably already having it restored and you need to replace it again.

## How to use
1. Clone the repo:
```
git clone https://github.com/SwimmingTiger/wine-fakesc.git
```
2. Start Windows Explorer with the following command:
```
wine explorer.exe
```
3. Copy `sc.exe` in `wine-fakesc/bin-x64-static` if you have a 64bit Wine prefix.
   Or copy `sc.exe` in `wine-fakesc/bin-x86-static` if you have a 32bit Wine prefix.
4. Enter `C:\windows\system32`, rename `sc.exe` to `sc.ori.exe`, then paste your `sc.exe` here.
5. Do not close `explorer.exe`, find your packaged installer in the explorer window and execute it. If you have closed the window, the changes to `sc.exe` may have been restored and you need to replace it again.

## Build
```
# install build toolchain
sudo apt-get install mingw-w64

# build
cd wine-fakesc
./build.sh
```

The output directories are `wine-fakesc/bin-x64-static` and `wine-fakesc/bin-x86-static`.

## Success Cases
The following packages can be installed under Wine after using this replacement:
* TableauDesktop-64bit-2019-3-0.exe
* TableauDesktop-64bit-2018-3-11.exe
* TableauDesktop-64bit-2018-1-17.exe
* TableauDesktop-32bit-10-4-21.exe
