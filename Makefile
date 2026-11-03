TARGET = final.exe

CXX = g++
CXXFLAGS = -Wall -std=c++17
INCLUDES = -IHeader
LDFLAGS = -static

SOURCES = \
    main.cpp \
    CPP/Hanghoa.cpp \
    CPP/ThucPham.cpp \
    CPP/VatTu.cpp \
    CPP/Ncc.cpp \
    CPP/NccTrongNuoc.cpp \
    CPP/NccQuocTe.cpp \
    CPP/qlncc.cpp \
    CPP/Chitietphieunhap.cpp \
    CPP/Phieunhap.cpp \
    CPP/Dsphieunhap.cpp \
    CPP/Kho.cpp \
    CPP/Date.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $@ $(LDFLAGS)

run: $(TARGET)
	.\$(TARGET)

gui:
	if not exist build mkdir build
	qmake PBL2.pro -o build\Makefile
	mingw32-make -C build

run-gui: gui
	build\PBL2-GUI.exe

clean:
	del $(TARGET)