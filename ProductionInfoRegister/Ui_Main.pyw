from Ui_ProdctionInfoRegister import Ui_MainWindow 
from Ui_Confirm_Window import Ui_ConfirmWindow
from Ui_MessageBox import Ui_MessageBox
from Ui_LogIn import Ui_LogIn
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import sys,  re, os,  shutil,  zipfile,  datetime



#current User
CURRENT_USER = {0:'VISITOR', 
                            1:'VENDOR', 
                            2:'EMPLOYEE', 
                            3:'MANAGER', 
                            4:'SUPPER'}
#PARAMETERS
SWT_CONTAINER = 'C:/'
PLF_CONTAINER = 'C:/'
TPPACKAGE_CONTAINER = 'C:/'
BINDEF_CONTAINER =  'C:/'
Dummy_folder = 'c:/Dummy'
#define
TYPE_ALL_FILE = "All Files (*);;"
TYPE_TXT_FILE = "Text Files (*.txt);;"
TYPE_SWT_FILE = "SWT Files (*.swt);;"
TYPE_ZIP_FILE =  "zip Files (*.zip);;"

def None_Out(para,  words, str):
    if para == None:
        str = str + '\n'
        str = str + words
    return str
def confirm(words):
    Dialog = QtWidgets.QDialog()
    new_window = _Ui_ConfirmWindow()
    new_window.setupUi(Dialog)
    new_window.setwords(words)
    Dialog.show()
    return Dialog.exec_()
def getFolder(title, startfrom):  
    Widget = QtWidgets.QWidget();
    directory1 = QFileDialog.getExistingDirectory(
                                Widget,  
                                title,  
                                startfrom)                  
    return directory1
    
def getFile(title,  startfrom, type):  
    try:
        Widget = QtWidgets.QWidget();
        fileName1, filetype = QFileDialog.getOpenFileName(
                                    Widget,  
                                    title,  
                                    startfrom,  
                                    type)
        return fileName1
    except Exception as err:
        error_catch(str(err))
def getFiles(title,  startfrom, type):  
    Widget = QtWidgets.QWidget();
    fileName1, filetype = QFileDialog.getOpenFileNames(
                                Widget,  
                                title,  
                                startfrom,  
                                type)
    return fileName1
def SE_LogIn():
    Dialog = QtWidgets.QDialog()
    new_window = _Ui_LogIn()
    new_window.setupUi(Dialog)
    new_window.setTitle(Dialog, 'SE Login Window')
    Dialog.show()
    return Dialog.exec_()
def Vendor_LogIn():
    Dialog = QtWidgets.QDialog()
    new_window = _Ui_LogIn()
    new_window.setupUi(Dialog)
    new_window.setTitle(Dialog, 'Vendor Login Window')
    Dialog.show()
    return Dialog.exec_()

def error_catch(words):
    Dialog = QtWidgets.QDialog()
    new_window = _Ui_MessageBox()
    new_window.setupUi(Dialog)
    new_window.ok2close(Dialog)
    new_window.set_title('Error Happened!!')
    new_window.set_content(words)
    Dialog.show()
    return Dialog.exec_()
#Main Window
class _Ui_MainWindow(Ui_MainWindow):
#NOTE: Disable or Enable 
    def PLC_Disable(self):
        self.tab_2.setEnabled(0)

    def Enable_DeleteAModify(self):
        self.PB_Modify.setEnabled(1)
        self.PB__delete.setEnabled(1)
    def clearWindow(self):
        ok = confirm("All The message would be deleted!!")
        if ok == 1:
             self.fileSNameLineEdit.setText('')
             self.LE_SMIC_Prod_ID.setText('')
             self.LE_Test_Program_Directory.setText('')
             self.LE_Probe_Card_Setup_Name.setText('')
             self.LE_Grid_Xmax.setText('')
             self.LE_Grid_Ymax.setText('')
             self.LE_Grid_Xmin.setText('')
             self.LE_Grid_Ymin.setText('')
             self.LE_shift_X.setText('')
             self.LE_shift_Y.setText('')
             self.LE_Fab_Site.setText('')
             self.LE_Test_Site.setText('')
             self.LE_Probe_Card_ID.setText('')
             self.LE_WM_ORIGIN.setText('')
             self.LE_Load_Board_ID.setText('')
             self.LE_ROM_Code.setText('')
             self.LE_X_Die_Size.setText('')
             self.LE_Y_Die_Size.setText('')
             self.LE_X_Street.setText('')
             self.LE_Y_Street.setText('')
             self.LE_Customer_Code.setText('')
             self.LE_Customer_PartID.setText('')
             self.LE_Gross_Die.setText('')
             self.LE_Prr_Check_Number.setText('')
             self.LE_Magnum_UI_Version.setText('')
             self.LE_Datalog_Setup.setText('')
             self.LE_ReleaseTester.setText('')
             self.LE_ServerDirectory.setText('')
             self.LE_Tester_Directory.setText('')
             self.sortLineEdit_2.setText('')
             self.packageLineEdit_2.setText('')
             self.programNameLineEdit_2.setText('')
             self.binDefinationLineEdit_2.setText('')
#NOTE:style
    def setStyle(self):
        QApplication.setStyle("WindowsVista")
        
#NOTE: Read Necessary Info From Server
    def createPLF(self):
        max_row = self.Table1.rowCount()
        Test_Program_Package   = ','
        Test_flow                     = ','
        Sort_ID                        = ','
        Test_Program                = ','
        Bin_Definition_File         = ','
        for row in range(max_row):
            Test_Program_Package  += self.Table1.item(row,  2).text()+','
            Test_flow                     += self.Table1.item(row,  1).text()+','
            Sort_ID                       += self.Table1.item(row,  0).text()+','
            Test_Program               += self.Table1.item(row,  3).text()+','
            Bin_Definition_File        += self.Table1.item(row,  4).text()+','
        try:
            PLF = open(PLF_CONTAINER+self.fileSNameLineEdit.text(), "w")
            PLF.write('SMIC_Prod_ID:'+str(self.LE_SMIC_Prod_ID.text())+
                            '\nTest_Program_Package:'+ Test_Program_Package+
                            '\nTest_Program_Directory:'+str(self.LE_Test_Program_Directory.text())+
                            '\nTester_Directory:'+str(self.LE_Tester_Directory.text())+
                            '\nTest_flow:'+Test_flow+
                            '\nSort_ID:'+Sort_ID+
                            '\nTest_Program:'+Test_Program+
                            '\nProbe_Card_Setup_Name:'+str(self.LE_Probe_Card_Setup_Name.text())+
                            '\nNotch_side:'+str(self.CB_Notch_side.currentText())+
                            '\nSwitch_Notch:'+str(self.CB_Switch_Notch.currentText())+
                            '\nBin_Definition_File:'+Bin_Definition_File+
                            '\nGrid_Xmax:'+str(self.LE_Grid_Xmax.text())+
                            '\nGrid_Ymax:'+str(self.LE_Grid_Ymax.text())+
                            '\nGrid_Xmin:'+str(self.LE_Grid_Xmin.text())+
                            '\nGrid_Ymin:'+str(self.LE_Grid_Ymin.text())+
                            '\nshift_X:'+str(self.LE_shift_X.text())+
                            '\nshift_Y:'+str(self.LE_shift_Y.text())+
                            '\nFab_Site:'+str(self.LE_Fab_Site.text())+
                            '\nTest_Site:'+str(self.LE_Test_Site.text())+
                            '\nProbe_Card_ID:'+str(self.LE_Probe_Card_ID.text())+
                            '\nWM_ORIGIN:'+str(self.LE_WM_ORIGIN.text())+
                            '\nLoad_Board_ID:'+str(self.LE_Load_Board_ID.text())+
                            '\nROM_Code:'+str(self.LE_ROM_Code.text())+
                            '\nX Die Size:'+str(self.LE_X_Die_Size.text())+
                            '\nY Die Size:'+str(self.LE_Y_Die_Size.text())+
                            '\nX_Street:'+str(self.LE_X_Street.text())+
                            '\nY_Street:'+str(self.LE_Y_Street.text())+
                            '\nCustomer_Code:'+str(self.LE_Customer_Code.text())+
                            '\nCustomer_PartID:'+str(self.LE_Customer_PartID.text())+
                            '\nGross_Die:'+str(self.LE_Gross_Die.text())+
                            '\nPrr_Check_Number:'+str(self.LE_Prr_Check_Number.text())+
                            '\nMagnum_UI_Version:'+str(self.LE_Magnum_UI_Version.text())+
                            '\nDatalog_Setup:'+str(self.LE_Datalog_Setup.text())+
                            '\nReleaseTester:'+str(self.LE_ReleaseTester.text())+
                            '\nServerDirectory:'+str(self.LE_ServerDirectory.text())
            )

            PLF.close()
            confirm('PLF created successfully!!')
        except Exception as err:
            error_catch('Fail to Create PLF\n1.Please check the PLF_CONTAINER\n2.Please check whether have you typed in PLF Name');

    def openPLF(self):
        try:
            path = getFile('Select PLF file',  PLF_CONTAINER, TYPE_ALL_FILE)
            if path == '':
                return 0
            PLF = open(path, 'r')
            content = PLF.read()
        except Exception as err:
            error_catch('Fail to Open PLF file')
            return 0
        #rules
        SMIC_Prod_ID = re.compile(r'SMIC_Prod_ID:(\w+(-(\w+)?)+)\n')
        Test_Program_Directory = re.compile(r'Test_Program_Directory:(((\w)?(\\)?(:)?)+)\n')
        Tester_Directory = re.compile(r'Tester_Directory:(((\w)?(\\)?(:)?)+)\n')
        Probe_Card_Setup_Name = re.compile(r'Probe_Card_Setup_Name:(((\w)?(\.)?)+)\n')
        Notch_side = re.compile(r'Notch_side:(\w)\n')
        Switch_Notch= re.compile(r'Switch_Notch:(\d+)\n')
        Grid_Xmax = re.compile(r'Grid_Xmax:(\d+)\n')
        Grid_Ymax = re.compile(r'Grid_Ymax:(\d+)\n')
        Grid_Xmin = re.compile(r'Grid_Xmin:(\d+)\n')
        Grid_Ymin = re.compile(r'Grid_Ymin:(\d+)\n')
        shift_X = re.compile(r'shift_X:(\d+)\n')
        shift_Y = re.compile(r'shift_Y:(\d+)\n')
        Fab_Site = re.compile(r'Fab_Site:(\w+)\n')
        Test_Site = re.compile(r'Test_Site:(\w+)\n')
        Probe_Card_ID = re.compile(r'Probe_Card_ID:(((\w)?(-)?(,)?)+)\n')
        WM_ORIGIN = re.compile(r'WM_ORIGIN:(\w+)\n')
        Load_Board_ID = re.compile(r'Load_Board_ID:(((\w)?(\\)?(:)?(,)?)+)\n')
        ROM_Code = re.compile(r'ROM_Code:(((\w)?(\\)?(:)?(,)?(\|)?(-)?)+)\n')
        X_Die_Size = re.compile(r'X Die Size:(\w+)\n')
        Y_Die_Size = re.compile(r'Y Die Size:(\w+)\n')
        X_Street = re.compile(r'X_Street:(\d+)\n')
        Y_Street = re.compile(r'Y_Street:(\d+)\n')
        Customer_Code = re.compile(r'Customer_Code:(((\w)?(-)?)+)\n')
        Customer_PartID = re.compile(r'Customer_PartID:(((\w)?(-)?)+)\n')
        Gross_Die = re.compile(r'Gross_Die:(\d+)\n')
        Prr_Check_Number = re.compile(r'Prr_Check_Number:(\d+)\n')
        Magnum_UI_Version  = re.compile(r'Magnum_UI_Version:(((\w)?(\.)?)+)\n')
        Datalog_Setup = re.compile(r'Datalog_Setup:(((\w)?(\\)?(:)?)+)\n')
        ReleaseTester = re.compile(r'ReleaseTester:(\w+)\n')
        ServerDirectory = re.compile(r'ServerDirectory:(((\w)?(\\)?(:)?)+)\n')
        Test_Program_Package = re.compile(r'Test_Program_Package:,(((\w)?(:)?(\\)?(\.)?(-)?(,)?)+)\n')
        Test_flow=re.compile(r'Test_flow:,(((\w)?(:)?(\\)?(\.)?(-)?(,)?)+)\n')
        Sort_ID=re.compile(r'Sort_ID:,(((\w)?(:)?(\\)?(\.)?(-)?(,)?)+)\n')
        Test_Program =re.compile(r'Test_Program:,(((\w)?(:)?(\\)?(\.)?(-)?(,)?)+)\n')
        Bin_Definition_File = re.compile(r'Bin_Definition_File:,(((\w)?(:)?(\\)?(\.)?(-)?(,)?)+)\n')
        
        #searching
        _SMIC_Prod_ID = SMIC_Prod_ID.search(content)
        _Test_Program_Directory = Test_Program_Directory.search(content)
        _Tester_Directory = Tester_Directory.search(content)
        _Probe_Card_Setup_Name =Probe_Card_Setup_Name.search(content)
        _Notch_side = Notch_side.search(content)
        _Switch_Notch = Switch_Notch.search(content)
        _Grid_Xmax = Grid_Xmax.search(content)
        _Grid_Ymax = Grid_Ymax.search(content)
        _Grid_Xmin = Grid_Xmin.search(content)
        _Grid_Ymin = Grid_Ymin.search(content)
        _shift_X = shift_X.search(content)
        _shift_Y = shift_Y.search(content)
        _Fab_Site = Fab_Site.search(content)
        _Test_Site = Test_Site.search(content)
        _Probe_Card_ID = Probe_Card_ID.search(content)
        _WM_ORIGIN = WM_ORIGIN.search(content)
        _Load_Board_ID = Load_Board_ID.search(content)
        _ROM_Code = ROM_Code.search(content)
        _X_Die_Size = X_Die_Size.search(content)
        _Y_Die_Size = Y_Die_Size.search(content)
        _X_Street = X_Street.search(content)
        _Y_Street = Y_Street.search(content)
        _Customer_Code =  Customer_Code.search(content)
        _Customer_PartID    = Customer_PartID.search(content)   
        _Gross_Die          = Gross_Die.search(content)           
        _Prr_Check_Number   = Prr_Check_Number.search(content)    
        _Magnum_UI_Version  = Magnum_UI_Version.search(content)   
        _Datalog_Setup      = Datalog_Setup.search(content)       
        _ReleaseTester      = ReleaseTester.search(content)       
        _ServerDirectory    = ServerDirectory.search(content)     
        _Test_Program_Package = Test_Program_Package.search(content)
        _Test_flow = Test_flow.search(content)
        _Sort_ID = Sort_ID.search(content)
        _Test_Program = Test_Program.search(content)
        _Bin_Definition_File = Bin_Definition_File.search(content)
        #error catch

        str = '[Fail to Read]'
        str = None_Out(_Test_flow,              'Fail at Read Test_flow',  str)
        str = None_Out(_Sort_ID,                'Fail at Read Sort_ID',  str)
        str = None_Out(_Test_Program,       'Fail at Read Test_Program',  str)
        str = None_Out(_Bin_Definition_File,  'Fail at Read Bin_Definition_File',  str)
        str = None_Out(_Test_Program_Package,  'Fail at Test_Program_Package ',  str)
        str = None_Out(_SMIC_Prod_ID           ,'SMIC_Prod_ID           Empty ',str)
        str = None_Out(_Test_Program_Directory ,'Test_Program_Directory Empty ',str)
        str = None_Out(_Tester_Directory       ,'Tester_Directory       Empty ',str)
        str = None_Out(_Probe_Card_Setup_Name  ,'Probe_Card_Setup_Name  Empty ',str)
        str = None_Out(_Notch_side             ,'Notch_side             Empty ',str)
        str = None_Out(_Switch_Notch           ,'Switch_Notch           Empty ',str)
        str = None_Out(_Grid_Xmax              ,'Grid_Xmax              Empty ',str)
        str = None_Out(_Grid_Ymax              ,'Grid_Ymax              Empty ',str)
        str = None_Out(_Grid_Xmin              ,'Grid_Xmin              Empty ',str)
        str = None_Out(_Grid_Ymin              ,'Grid_Ymin              Empty ',str)
        str = None_Out(_shift_X                ,'shift_X                Empty ',str)
        str = None_Out(_shift_Y                ,'shift_Y                Empty ',str)
        str = None_Out(_Fab_Site               ,'Fab_Site               Empty ',str)
        str = None_Out(_Test_Site              ,'Test_Site              Empty ',str)
        str = None_Out(_Probe_Card_ID          ,'Probe_Card_ID          Empty ',str)
        str = None_Out(_WM_ORIGIN              ,'WM_ORIGIN              Empty ',str)
        str = None_Out(_Load_Board_ID          ,'Load_Board_ID          Empty ',str)
        str = None_Out(_ROM_Code               ,'ROM_Code               Empty ',str)
        str = None_Out(_X_Die_Size             ,'X_Die_Size             Empty ',str)
        str = None_Out(_Y_Die_Size             ,'Y_Die_Size             Empty ',str)
        str = None_Out(_X_Street               ,'X_Street               Empty ',str)
        str = None_Out(_Y_Street               ,'Y_Street               Empty ',str)
        str = None_Out(_Customer_Code          ,'Customer_Code          Empty ',str)
        str = None_Out(_Customer_PartID        ,'Customer_PartID        Empty ',str)
        str = None_Out(_Gross_Die              ,'Gross_Die              Empty ',str)
        str = None_Out(_Prr_Check_Number       ,'Prr_Check_Number       Empty ',str)
        str = None_Out(_Magnum_UI_Version      ,'Magnum_UI_Version      Empty ',str)
        str = None_Out(_Datalog_Setup          ,'Datalog_Setup          Empty ',str)
        str = None_Out(_ReleaseTester          ,'ReleaseTester          Empty ',str)
        str = None_Out(_ServerDirectory        ,'ServerDirectory        Empty ',str)
        if str != '[Fail to Read]':
            error_catch(str)
            return 0
        #end        
        __Test_Program_Package = _Test_Program_Package.group(1)
        __Test_flow = _Test_flow.group(1)
        __Sort_ID = _Sort_ID.group(1)
        __Test_Program = _Test_Program.group(1)
        __Bin_Definition_File = _Bin_Definition_File.group(1)
        
        Package_Array = __Test_Program_Package.split(',')
        Test_flow_Array = __Test_flow.split(',')
        Sort_ID_Array = __Sort_ID.split(',')
        Test_Program_Array = __Test_Program.split(',')
        Bin_Definition_File_Array = __Bin_Definition_File.split(',')
        
        if len(Package_Array) != len(Test_flow_Array) != len(Sort_ID_Array) != len(Test_Program_Array) != len(Bin_Definition_File_Array):
            error_catch('Record count of {Test_Program_Package}&{Bin_Definition_File}&{Test_Program}&{Sort_ID}&{Test_flow} Not Match')
            return 0
        self.Table1.setRowCount(len(Package_Array))
        for i in range(len(Package_Array)):
            data1 = QTableWidgetItem(Sort_ID_Array[i])
            data2 = QTableWidgetItem(Test_flow_Array[i])
            data3 = QTableWidgetItem(Package_Array[i])
            data4 = QTableWidgetItem(Test_Program_Array[i])
            data5 = QTableWidgetItem(Bin_Definition_File_Array[i])
        
            self.Table1.setItem(i, 0, data1)
            self.Table1.setItem(i, 1, data2)
            self.Table1.setItem(i, 2, data3)
            self.Table1.setItem(i, 3, data4)
            self.Table1.setItem(i, 4, data5)

            
        self.LE_SMIC_Prod_ID.setText(_SMIC_Prod_ID.group(1))
        self.LE_Test_Program_Directory.setText(_Test_Program_Directory.group(1))
        self.LE_Tester_Directory.setText(_Tester_Directory.group(1))
        self.LE_Probe_Card_Setup_Name.setText(_Probe_Card_Setup_Name.group(1))
        self.CB_Notch_side.setCurrentText(_Notch_side.group(1))
        self.CB_Switch_Notch.setCurrentText(_Switch_Notch.group(1))
        self.LE_Grid_Xmax.setText(_Grid_Xmax.group(1))
        self.LE_Grid_Ymax.setText(_Grid_Ymax.group(1))
        self.LE_Grid_Xmin.setText(_Grid_Xmin.group(1))
        self.LE_Grid_Ymin.setText(_Grid_Ymin.group(1))
        self.LE_shift_X.setText(_shift_X.group(1))
        self.LE_shift_Y.setText(_shift_Y.group(1))
        self.LE_Fab_Site.setText(_Fab_Site.group(1))
        self.LE_Test_Site.setText(_Test_Site.group(1))
        self.LE_Probe_Card_ID.setText(_Probe_Card_ID.group(1))
        self.LE_WM_ORIGIN.setText(_WM_ORIGIN.group(1))
        self.LE_Load_Board_ID.setText(_Load_Board_ID.group(1))
        self.LE_ROM_Code.setText(_ROM_Code.group(1))
        self.LE_X_Die_Size.setText(_X_Die_Size.group(1))
        self.LE_Y_Die_Size.setText(_Y_Die_Size.group(1))
        self.LE_X_Street.setText(_X_Street.group(1))
        self.LE_Y_Street.setText(_Y_Street.group(1))
        self.LE_Customer_Code.setText(_Customer_Code.group(1))
        self.LE_Customer_PartID.setText(_Customer_PartID.group(1))
        self.LE_Gross_Die.setText(_Gross_Die.group(1))
        self.LE_Prr_Check_Number.setText(_Prr_Check_Number.group(1))
        self.LE_Magnum_UI_Version.setText(_Magnum_UI_Version.group(1))
        self.LE_Datalog_Setup.setText(_Datalog_Setup.group(1))
        self.LE_ReleaseTester.setText(_ReleaseTester.group(1))
        self.LE_ServerDirectory.setText(_ServerDirectory.group(1))
    
        
    def select_SWT(self):
        buffer = getFile( "Select SWT file", SWT_CONTAINER,  TYPE_SWT_FILE+TYPE_ALL_FILE)
        if buffer == '':
            return 0
        SWT_FileNameSearch = re.compile(r'/(\w+\.swt)')
        _SWT = SWT_FileNameSearch.search(buffer)
        if _SWT == None:
            error_catch('Illegal SWT fileName!')
            return 0
        else:
            SWT = _SWT.group(1)
            self.LE_Probe_Card_Setup_Name.setText(SWT)
            return 1
            
    def select_TPPackage(self):
        pack = getFile( "Select TP Package", TPPACKAGE_CONTAINER,  TYPE_ZIP_FILE)        
        if pack == '':
            return 0 
        name = self.read_TPName(pack)
        self.packageLineEdit_2.setText(pack)
        self.programNameLineEdit_2.setText(name)
        return 1
        
    def select_BinDef(self):
        buffer = getFile( "Select TP Package", BINDEF_CONTAINER,  TYPE_ALL_FILE)        
        if buffer == '':
            return ;
        BinDef_FileNameSearch = re.compile(r'/(((\w)?(-)?)+)$')
        _BinDef = BinDef_FileNameSearch.search(buffer)
        if _BinDef == None:
            error_catch('SomeThing Wrong Happened During Read Bin Defination File')
        else:
            BinDef = _BinDef.group(1)
            self.binDefinationLineEdit_2.setText(BinDef)
            return 1
            

        BINDEF_CONTAINER
    def read_TPName(self, zip):
        try:
            count = 0
            #str1 = ''
            Find_EXE = re.compile(r'Debug/(\w+)\.exe$')
            EXE_Name = ''
            #start
            if os.path.exists(Dummy_folder) :
                shutil.rmtree(Dummy_folder)
            os.makedirs(Dummy_folder)
            Get_zipFileName = re.compile(r'/((\w)+.zip)$')
            _zip_Name = Get_zipFileName.search(zip)
            if _zip_Name == None:
                raise Exception('Fail to get zip FileName')
            zip_Name = _zip_Name.group(1)
            #copy file
            shutil.copy(zip, Dummy_folder)
            ZIP = zipfile.ZipFile(Dummy_folder+'\\'+zip_Name)
            list = ZIP.namelist()
            for i in range(len(list)):
                mo = Find_EXE.search(list[i])
                if mo != None:
                    count += 1
                    EXE_Name = mo.group(1)
                #str1 += list[i]
                #str1 += '\n'
            if count == 0:
                 raise Exception('There is no exe find in the package, please type in it')
            elif count > 1:
                raise Exception('There is too many .exe file in your package\'s Debug folder, please take a look')
            ZIP.close()
            shutil.rmtree(Dummy_folder)
            return EXE_Name
           
            
        except Exception as err:
            error_catch(str('Error happened in checking package!\n code as:'+str(err)))
#NOTE: TABLE FUNC
    def update(self):
        max_row = self.Table1.rowCount()
        current_row = max_row +1
        self.Table1.setRowCount(current_row)
        data1 = QTableWidgetItem(self.sortLineEdit_2.text())
        data2 = QTableWidgetItem(self.comboBox_2.currentText())
        data3 = QTableWidgetItem(self.packageLineEdit_2.text())
        data4 = QTableWidgetItem(self.programNameLineEdit_2.text())
        data5 = QTableWidgetItem(self.binDefinationLineEdit_2.text())
    
        self.Table1.setItem(current_row-1, 0, data1)
        self.Table1.setItem(current_row-1, 1, data2)
        self.Table1.setItem(current_row-1, 2, data3)
        self.Table1.setItem(current_row-1, 3, data4)
        self.Table1.setItem(current_row-1, 4, data5)
        
        self.sortLineEdit_2.setText('')
        self.comboBox_2.setCurrentText('')
        self.packageLineEdit_2.setText('')
        self.programNameLineEdit_2.setText('')
        self.binDefinationLineEdit_2.setText('')
        self.PB_Update.setEnabled(0)



    def modify(self):
        if self.PB_Modify.text() == 'Modify':
            row = self.Table1.currentRow()
            sortID        =  self.Table1.item(row,  0).text()
            TestFlow     = self.Table1.item(row,  1).text()
            Package     = self.Table1.item(row,  2).text()
            ProgramName = self.Table1.item(row,  3).text()
            Bin_def = self.Table1.item(row,  4).text()
            
            self.sortLineEdit_2.setText(sortID)
            self.comboBox_2.setCurrentText(TestFlow)
            self.packageLineEdit_2.setText(Package)
            self.programNameLineEdit_2.setText(ProgramName)
            self.binDefinationLineEdit_2.setText(Bin_def)
            
            self.PB_Update.setEnabled(0)
            
            self.PB_Modify.setText('Done')
        elif self.PB_Modify.text() == 'Done':
            row = self.Table1.currentRow()
            
            data1 = QTableWidgetItem(self.sortLineEdit_2.text())
            data2 = QTableWidgetItem(self.comboBox_2.currentText())
            data3 = QTableWidgetItem(self.packageLineEdit_2.text())
            data4 = QTableWidgetItem(self.programNameLineEdit_2.text())
            data5 = QTableWidgetItem(self.binDefinationLineEdit_2.text())
            
            self.Table1.setItem(row, 0, data1)
            self.Table1.setItem(row, 1, data2)
            self.Table1.setItem(row, 2, data3)
            self.Table1.setItem(row, 3, data4)
            self.Table1.setItem(row, 4, data5)
            
            self.sortLineEdit_2.setText('')
            self.comboBox_2.setCurrentText('')
            self.packageLineEdit_2.setText('')
            self.programNameLineEdit_2.setText('')
            self.binDefinationLineEdit_2.setText('')
            self.PB_Modify.setText('Modify')

    def delete(self):
        row = self.Table1.currentRow()
        self.Table1.removeRow(row)


#NOTE: CHECK STATE
    def check_DataComplete(self):
        if self.PB_Modify.text() != 'Done' and self.sortLineEdit_2.text != '' and self.comboBox_2.currentText() != '' and self.packageLineEdit_2.text() != '' and self.programNameLineEdit_2.text() != '' and self.binDefinationLineEdit_2.text() != '':
            self.PB_Update.setEnabled(1)
#NOTE: MainWindow Logic from here
    def logic(self, MainWindow):
        self.setStyle()
        #禁止拉伸窗口大小  
        MainWindow.setFixedSize(MainWindow.width(), MainWindow.height());  
        #Initial
        self.PB_Modify.setEnabled(0)
        self.PB__delete.setEnabled(0)
        self.PB_Update.setEnabled(0)
        #Search and Check
        self.sortLineEdit_2.textChanged.connect(self.check_DataComplete)
        self.packageLineEdit_2.textChanged.connect(self.check_DataComplete)
        self.programNameLineEdit_2.textChanged.connect(self.check_DataComplete)
        self.binDefinationLineEdit_2.textChanged.connect(self.check_DataComplete)
        self.comboBox_2.currentTextChanged.connect(self.check_DataComplete)

        #button slots connection
        MainWindow.setWindowIcon(QIcon('G:\\ProductionInfoRegister\\resource\\app_info.ico'))
        self.BTN_Clear.clicked.connect(lambda: self.clearWindow())
        self.PB_Probe_Card_Setup_Name.clicked.connect(lambda:self.select_SWT())
        self.BTN_Create.clicked.connect(lambda:self.createPLF())
        self.PB_Package.clicked.connect(self.select_TPPackage)
        self.PB_BinDef.clicked.connect(self.select_BinDef)
        self.PB_Update.clicked.connect(self.update)
        self.PB_Modify.clicked.connect(self.modify)
        self.PB__delete.clicked.connect(self.delete)
        #Meau slots connection
        self.actionFor_SE.triggered.connect(SE_LogIn)
        self.actionFor_Vender.triggered.connect(Vendor_LogIn)
        self.actionProduction_Load_File.triggered.connect(self.openPLF)
        #table slots connection
        self.Table1.itemSelectionChanged.connect(self.Enable_DeleteAModify)
        
#NOTE: [WIN]CONFIRM WINDOW
class _Ui_ConfirmWindow(Ui_ConfirmWindow):
    def setwords(self, words):
        self.label.setText(words)
#NOTE: [WIN]LOGIN DIALOG
class _Ui_LogIn(Ui_LogIn):
    def setTitle(self, Dialog, words):
        Dialog.setWindowTitle(words)
        
#NOTE: [WIN]MESSAGE BOX
class _Ui_MessageBox(Ui_MessageBox):
    def set_title(self, words):
        self.groupBox.setTitle(words)
    def set_content(self, words):
        self.plainTextEdit.setPlainText(words)
    def ok2close(self, Dialog):
        self.pushButton.clicked.connect(Dialog.close)
#NOTE: Start From here
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = _Ui_MainWindow()
    ui.setupUi(MainWindow)
    #ui.PLC_Disable()
    ui.logic(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

