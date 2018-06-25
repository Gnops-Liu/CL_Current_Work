# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'G:\ProductionInfoRegister\MessageBox.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MessageBox(object):
    def setupUi(self, MessageBox):
        MessageBox.setObjectName("MessageBox")
        MessageBox.resize(405, 275)
        MessageBox.setSizeGripEnabled(True)
        self.pushButton = QtWidgets.QPushButton(MessageBox)
        self.pushButton.setGeometry(QtCore.QRect(150, 230, 75, 23))
        self.pushButton.setObjectName("pushButton")
        self.groupBox = QtWidgets.QGroupBox(MessageBox)
        self.groupBox.setGeometry(QtCore.QRect(20, 20, 351, 201))
        self.groupBox.setObjectName("groupBox")
        self.plainTextEdit = QtWidgets.QPlainTextEdit(self.groupBox)
        self.plainTextEdit.setGeometry(QtCore.QRect(10, 20, 331, 171))
        self.plainTextEdit.setObjectName("plainTextEdit")

        self.retranslateUi(MessageBox)
        QtCore.QMetaObject.connectSlotsByName(MessageBox)

    def retranslateUi(self, MessageBox):
        _translate = QtCore.QCoreApplication.translate
        MessageBox.setWindowTitle(_translate("MessageBox", "Dialog"))
        self.pushButton.setText(_translate("MessageBox", "ok"))
        self.groupBox.setTitle(_translate("MessageBox", "Message Box"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MessageBox = QtWidgets.QDialog()
    ui = Ui_MessageBox()
    ui.setupUi(MessageBox)
    MessageBox.show()
    sys.exit(app.exec_())

