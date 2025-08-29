# DummyAdd (Intel SGX, SIM mode)

Dummy SGX enclave that **exposes** an ECALL `add(a, b)` and uses an OCALL to print a message.

## 1) Install the Intel SGX SDK (SIM mode)

```bash
# Get the installer
$ wget https://download.01.org/intel-sgx/latest/linux-latest/distro/ubuntu24.04-server/sgx_linux_x64_sdk_2.26.100.0.bin
```
```bash
# Make it executale and run it
$ chmod +x sgx_linux_x64_sdk_2.26.100.0.bin
$ ./sgx_linux_x64_sdk_2.26.100.0.bin --prefix "$HOME/sgxsdk-2.26
```
```bash
# Load the environment for this shell
$ source "$HOME/sgxsdk-2.26/sgxsdk/environment"
```

## 2) Build & run
```bash
# From the repository root
$ make clean
$ make SGX_MODE=SIM
```
```bash
# Run the application
./app
```
```bash
# Expected output:
[OCALL] Hello from enclave, computing a+b...
40 + 2 = 42 (from enclave)
```