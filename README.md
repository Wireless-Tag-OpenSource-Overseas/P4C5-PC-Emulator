# tiny386 on ESP32-P4 —— Windows 95 复刻版

## 项目简介

本项目将开源 x86 PC 模拟器 tiny386 移植到 ESP32-P4 微控制器，在单片机上运行 **Windows 95** 操作系统。

- 目标芯片：ESP32-P4 (WT99P4C5-S1 开发板)
- 显示：MIPI DSI 1024×600 LCD，硬件旋转适配
- 存储：MicroSD 卡 (SDMMC 4-bit 高速模式)
- 输入：USB 键盘 / 鼠标
- 音频：I2S 立体声 (AdLib + Sound Blaster 16)

## 硬件要求

| 组件 | 规格 |
|------|------|
| 开发板 | WT99P4C5-S1 (ESP32-P4, 16MB Flash, PSRAM) |
| 显示屏 | EK79007 MIPI DSI 1024×600 |
| 存储 | MicroSD 卡, FAT32, ≥ 512MB |
| 输入 | USB 键盘 + 鼠标 (USB-OTG) |
| 供电 | USB-C 5V/2A |

## 软件环境

- ESP-IDF **v5.5.4**
- Python 3.11+
- CMake ≥ 3.16

## 构建

```bash
# 1. 激活 ESP-IDF
. /path/to/esp-idf/export.sh

# 2. 进入 ESP 目录
cd esp

# 3. 设置目标芯片
idf.py set-target esp32p4

# 4. 编译
idf.py build

# 5. 烧录 (替换 COMx 为实际端口)
idf.py -p COMx flash
```

## SD 卡准备

将以下文件放入 SD 卡根目录 (FAT32)：

```
SD卡:/
├── bios.bin          # 从 out/ 目录复制
├── vgabios.bin       # 从 out/ 目录复制
├── win95.img         # Windows 95 磁盘镜像 
├── win31.img         # Windows 3.1 磁盘镜像（拓展）
└── tiny386.ini       # 配置文件 (见下)
```

> 磁盘镜像需自行使用合法安装介质通过 QEMU 等工具创建。

## 配置

`tiny386.ini` — Windows 95 默认配置：

```ini
[esp]
ssid =
pass =

[pc]
bios = /sdcard/bios.bin
vga_bios = /sdcard/vgabios.bin
mem_size = 64M
vga_mem_size = 768K
hda = /sdcard/win95.img
fill_cmos = 1

[display]
width = 1024
height = 600

[cpu]
gen = 4
fpu = 0
```

## 项目拓展：Windows 3.1

同一硬件平台也支持运行 Windows 3.1。修改 `tiny386.ini` 即可切换：

```ini
[pc]
hda = /sdcard/win31.img
mem_size = 16M
vga_mem_size = 320K

[cpu]
gen = 3
fpu = 0
```

## 许可

基于原 [tiny386](https://github.com/hchunhui/tiny386) 项目 (BSD-3-Clause)。SeaBIOS 使用 LGPL-3。部分 QEMU/TinyEMU 移植代码使用 MIT。
