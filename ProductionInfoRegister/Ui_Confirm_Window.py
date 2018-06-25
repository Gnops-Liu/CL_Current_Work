# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'G:\ProductionInfoRegister\Confirm_Window.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_ConfirmWindow(object):
    def setupUi(self, ConfirmWindow):
        ConfirmWindow.setObjectName("ConfirmWindow")
        ConfirmWindow.resize(383, 191)
        ConfirmWindow.setSizeGripEnabled(True)
        self.buttonBox = QtWidgets.QDialogButtonBox(ConfirmWindow)
        self.buttonBox.setGeometry(QtCore.QRect(20, 130, 341, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.label = QtWidgets.QLabel(ConfirmWindow)
        self.label.setGeometry(QtCore.QRect(40, 34, 301, 81))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label.setFont(font)
        self.label.setObjectName("label")

        self.retranslateUi(ConfirmWindow)
        self.buttonBox.accepted.connect(ConfirmWindow.accept)
        self.buttonBox.rejected.connect(ConfirmWindow.reject)
        QtCore.QMetaObject.connectSlotsByName(ConfirmWindow)

    def retranslateUi(self, ConfirmWindow):
        _translate = QtCore.QCoreApplication.translate
        ConfirmWindow.setWindowTitle(_translate("ConfirmWindow", "Dialog"))
        self.label.setText(_translate("ConfirmWindow", "Confirmed?"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    ConfirmWindow = QtWidgets.QDialog()
    ui = Ui_ConfirmWindow()
    ui.setupUi(ConfirmWindow)
    ConfirmWindow.show()
    sys.exit(app.exec_())

