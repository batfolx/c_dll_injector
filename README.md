# c_dll_injector
A small repo showing a dll injection

I was always interested in how DLL injection worked. It's actually easier than you might think. There are three components

- The DLL itself
- The Injector
- The victim/target process

The DLL is the library that is injected into a target process. The DLL has built-in functionality to run some first-time setup code, which can
be used maliciously. The injector simply looks for the target process and then loads this DLL into the target process address space, which then runs
the setup code in the DLL. [Here is a great resource explaining DLLMain.](https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain)

In this case, all the DLL does is open up a `MessageBoxA` with some text, so nothing too bad.

## How to do it yourself

### Step 1 - clone the repository

Execute the command 
```
git clone https://github.com/batfolx/c_dll_injector.git
```

and then `cd` into the `c_dll_injector` repository.

Make sure you have `git` as well as `cmake` installed.

### Step 2 - Build the executable

Run the command

```
cmake build .
```

This should make a bunch of files.

Then run the command 

```
cmake --build .
```

which will then place the executable in `Debug/dll_injector.exe`. You'll want to copy the executable into the current directory with this command
```
cp Debug/dll_injector.exe .
```

### Step 3 - Build the DLL (Optional - DLL is included in repository)

If you want to edit the DLL in `dll/virus.c` (I know, not really a virus) then you'll want to run the same commands as details in Step 2 above, all in the `dll` folder.
This will place the DLL in `dll/Debug/notvirus.dll`.

Then you want to copy the DLL and place it in the same directory as `dll_injector.exe`.

### Step 4 - Run

Make sure you have Task Manager open. (Open it quickly by doing `ctrl` + `shift` + `ESC`.)

Run the executable with 
```
./dll_injector.exe
```

If you get an error in the output, it probably means that you aren't running as `Administrator`. Make sure you are running your current shell as admin, and then try again.
If everything is successful, you will see that `notvirus.dll` will successfully be injected in Task Manager and a Message Box will pop up!
