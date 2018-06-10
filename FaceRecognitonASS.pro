QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    autoSellingSystem/goods.cpp \
    autoSellingSystem/goodsModel.cpp \
    autoSellingSystem/customers.cpp \
    autoSellingSystem/customersModel.cpp \
    autoSellingSystem/messageCenter.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    images/closet.jpeg \
#    images/coffee.jpeg \
#    images/cool.jpeg \
#    images/hmprod-1.jpeg \
#    images/hmprod-2.jpeg \
#    images/hmprod-3.jpeg \
#    images/hmprod-4.jpeg \
#    images/hmprod-5.jpeg \
#    images/hmprod.jpeg \
#    images/hotdrink.jpg \
#    images/juice.jpeg \
#    images/lemonate.jpeg \
#    images/login-icon.jpeg \
#    images/logout.jpeg \
#    images/pineapple.jpeg \
#    images/RIO.jpeg \
#    images/scream.jpg \
#    images/submit.jpg \
#    images/yeos.jpeg \
#    images/Add-Bag-icon.png \
#    images/Add-icon.png \
#    images/arrow-45-128.png \
#    images/arrow-back-128.png \
#    images/arrow-up-5-xxl.png \
#    images/buy-now.png \
#    images/cameraIcon.png \
#    images/done.png \
#    images/dress.png \
#    images/Edit-icon.png \
#    images/notification.png \
#    images/ok.png \
#    images/paint.png \
#    images/Pattern.png \
#    images/SHOP MY CLOSET.png \
#    images/Signup.png \
#    images/trash-icon.png \
#    images/color-wheel-target.svg

HEADERS += \
    autoSellingSystem/goods.h \
    autoSellingSystem/goodsModel.h \
    autoSellingSystem/customers.h \
    autoSellingSystem/customersModel.h \
    autoSellingSystem/messageCenter.h
