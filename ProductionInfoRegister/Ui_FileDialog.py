from PyQt5 import QtWidgets  
from PyQt5.QtWidgets import QFileDialog  
  
class Ui_FileDialog(QtWidgets.QWidget): 
    def get_path(self):  
        directory1 = QFileDialog.getExistingDirectory(self,  
                                    "选取文件夹",  
                                    "C:/")                                 #起始路径  
        return directory1
"""
        fileName1, filetype = QFileDialog.getOpenFileName(self,  
                                    "选取文件",  
                                    "C:/",  
                                    "All Files (*);;Text Files (*.txt)")   #设置文件扩展名过滤,注意用双分号间隔  
        print(fileName1,filetype)  
  
        files, ok1 = QFileDialog.getOpenFileNames(self,  
                                    "多文件选择",  
                                    "C:/",  
                                    "All Files (*);;Text Files (*.txt)")  
        print(files,ok1)  
  
        fileName2, ok2 = QFileDialog.getSaveFileName(self,  
                                    "文件保存",  
                                    "C:/",  
                                    "All Files (*);;Text Files (*.txt)")  
                                    
"""
