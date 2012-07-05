
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// cexcel.h



// COleVariant const	
COleVariant VOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);
COleVariant covFalse((short)FALSE);

void UINT2Cell2(UINT X, UINT Y, CString &Cell)
{
	char x1[10]; // StartX	
	int index=0;
	int rem=0;

	// cal x1
	memset(x1,0,10);
	index=0;
	do{
		rem = X%26, X = X/26;
		x1[index++] = rem + 'A' -1;
	}while(X!=0);
	x1[index]=0, strrev(x1);
	Cell.Format("%s%lu",x1,Y);
}

class CExcel
{
private:
	_Application objApp;
	Workbooks objBooks;
	_Workbook objBook;
	Worksheets objSheets;
	_Worksheet objSheet;

	LPDISPATCH lpDisp;
	VARIANT var;	
	Font font;
	Interior cell;
	Range range;	
	
	ChartObjects chartobjects;
	ChartObject chartobject;
	_Chart xlsChart;

private:
	void UINT2Cell(UINT StartX, UINT StartY, UINT EndX, UINT EndY, CString &StartCell, CString &EndCell);
	void GetRange(CString StartCell, CString EndCell);	
	void GetRange(UINT StartX, UINT StartY, UINT EndX, UINT EndY);
	CString *SheetName;
	UINT SheetCnt;
	UINT ActiveSheetIndex;
	
public:
	BOOL InitializeApp();
	BOOL OpenExistFile(CString FullPathName, BOOL VISIBLE);
	void OpenNewFile(BOOL VISIBLE);

	long GetStartColumn(); // �_�l��
	long GetStartRow(); // �_�l�C
	long GetTotalColumn(); // �`���
	long GetTotalRow(); // �`�C��
	
	long GetSheetNum(); // ���o sheet �Ӽ�	
	BOOL InsertSheet(long nIndex, CString SheetName); // ���J sheet
	BOOL DelSheetIndex(long nIndex); // start from 1 // �R��
	BOOL SetSheetName(long nIndex, CString SheetName); // start from 1 // �]�W	
	BOOL SetActiveSheet(long nIndex); // �]�w��e Sheet
	BOOL GetSheetName(long nIndex, CString &SheetName); // �� nSheet Name
	void GetSheetName(CString *SheetName); // ���o sheet name	
	
	void ClearRange(CString StartCell, CString EndCell);
	void ClearRange(UINT StartX, UINT StartY, UINT EndX, UINT EndY);
	
	void Merge(CString StartCell, CString EndCell); // �X���x�s��
	void Merge(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �X���x�s��
	void MergeAll(CString StartCell, CString EndCell); // �X���x�s��
	void MergeAll(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �X���x�s��

	void SetHorizontal(CString StartCell, CString EndCell, UINT Aligment); // 2:Left, 3:Center, 4:Right, 5:Repeat
	void SetHorizontal(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT Aligment); // 2:Left, 3:Center, 4:Right, 5:Repeat
	void SetHorizontalLeft(CString StartCell, CString EndCell); // �a�����
	void SetHorizontalLeft(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �a�����
	void SetHorizontalCenter(CString StartCell, CString EndCell); // �m�����
	void SetHorizontalCenter(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �m�����
	void SetHorizontalRight(CString StartCell, CString EndCell); // �a�k���
	void SetHorizontalRight(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �a�k���

	void SetVertical(CString StartCell, CString EndCell,UINT Alignment); // 1:UP 2:Down 3:Mid
	void SetVertical(UINT StartX, UINT StartY, UINT EndX, UINT EndY,UINT Alignment); // 1:UP 2:Down 3:Mid
	void SetVerticalUp(CString StartCell, CString EndCell); // �a�W
	void SetVerticalUp(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �a�W
	void SetVerticalDown(CString StartCell, CString EndCell); // �a�U
	void SetVerticalDown(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �a�U
	void SetVerticalMid(CString StartCell, CString EndCell); // �m��
	void SetVerticalMid(UINT StartX, UINT StartY, UINT EndX, UINT EndY); // �m��

	void Border(CString StartCell, CString EndCell, UINT LineStyle,UINT Weight,UINT ColorIndex); // LineStyle:1~5, 9, Weight:1-4
	void Border(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT LineStyle,UINT Weight,UINT ColorIndex); // LineStyle:1~5, 9, Weight:1-4
	

	void SetWidth(CString StartCell, CString EndCell, float width); // set field width
	void SetWidth(UINT Start, UINT End, float width); // set field width
	void SetHeight(CString StartCell, CString EndCell, float height); // set field height
	void SetHeight(UINT Start, UINT End, float height); // set field height

	void AutoSetWidth(CString StartCell, CString EndCell); // set field width
	void AutoSetWidth(UINT Start, UINT End); // set field width

	void SetFontName(CString StartCell, CString EndCell, CString FontName); // �r��
	void SetFontName(UINT StartX, UINT StartY, UINT EndX, UINT EndY, CString FontName); // �r��
	

	void SetFontBold(CString StartCell, CString EndCell, BOOL BOLD); // ����
	void SetFontBold(UINT StartX, UINT StartY, UINT EndX, UINT EndY, BOOL BOLD); // ����

	void SetFontStrikethrough(CString StartCell, CString EndCell, BOOL STRIKE); // �R���u
	void SetFontStrikethrough(UINT StartX, UINT StartY, UINT EndX, UINT EndY, BOOL STRIKE); // �R���u

	void SetFontSize(CString StartCell, CString EndCell, UINT FontSize); // �r��j�p
	void SetFontSize(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT FontSize); // �r��j�p

	void SetFontColor(CString StartCell, CString EndCell, UINT ColorIndex); // �r���C��	
	void SetFontColor(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT ColorIndex);

	void SetBkColor(CString StartCell, CString EndCell, UINT ColorIndex); // �I����
	void SetBkColor(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT ColorIndex);

	void SetFontFormat(CString StartCell, CString EndCell, CString FontName, UINT HorizontalFormat, UINT VerticalFormat,
		BOOL BOLD, BOOL STRIKE,UINT FontSize,UINT FontColorIndex,UINT BkColorIndex); // �]�j�d��榡
	void SetFontFormat(UINT StartX, UINT StartY, UINT EndX, UINT EndY, CString FontName, UINT HorizontalFormat,UINT VerticalFormat,
		BOOL BOLD, BOOL STRIKE,UINT FontSize,UINT FontColorIndex,UINT BkColorIndex); // �]�j�d��榡

	void SetCellTextFormat(CString Cell, CString FontName,UINT HorizontalFormat, UINT VerticalFormat, 
		BOOL BOLD, BOOL STRIKE,	UINT FontSize,UINT FontColorIndex,UINT BkColorIndex,CString Text); // �]��@Cell��r�ή榡
	void SetCellTextFormat(UINT X, UINT Y, CString FontName, UINT HorizontalFormat, UINT VerticalFormat, 
		BOOL BOLD, BOOL STRIKE,	UINT FontSize,UINT FontColorIndex,UINT BkColorIndex,CString Text); // �]��@Cell��r�ή榡
	

	void SetText(CString Cell, CString text); // �] Cell ��r 
	void SetText(UINT X, UINT Y, CString text); // �] Cell ��r

	CString ReadAsString(UINT X, UINT Y); // as string read
	CString ReadAsInteger(UINT X, UINT Y, int &value);
	CString ReadAsDouble(UINT X, UINT Y, double &value); // as double read
	CString ReadAsDate(UINT X, UINT Y, SYSTEMTIME& Date);
	CString ReadAsTime(UINT X, UINT Y, SYSTEMTIME& Time);
	CString ReadAsDateTime(UINT X, UINT Y, SYSTEMTIME& DateTime);
	

	CString ReadAsString(CString Cell); // as string read
	CString ReadAsInteger(CString Cell, int &value);
	CString ReadAsDouble(CString Cell, double &value); // as double read
	CString ReadAsDate(CString Cell, SYSTEMTIME& Date);
	CString ReadAsTime(CString Cell, SYSTEMTIME& Time);
	CString ReadAsDateTime(CString Cell, SYSTEMTIME& DateTime);

	void Sort1(CString StartCell, CString EndCell, CString IndexCell, long DeCrement);; // Decrement:1 �� 2 �@
	void Sort1(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT Cell1, UINT Cell2, long DeCrement);; // Decrement:1 �� 2 �@

	void Sort2(CString StartCell, CString EndCell, CString IndexCell1, long DeCrement1, CString IndexCell2, long DeCrement2); // Decrement:1 �� 2 �@
	void Sort2(UINT StartX, UINT StartY, UINT EndX, UINT EndY,
		UINT IndexCell1X, UINT IndexCell1Y, long DeCrement1,
		UINT IndexCell2X, UINT IndexCell2Y, long DeCrement2);// Decrement:1 �� 2 �@

	void Sort3(CString StartCell, CString EndCell, CString IndexCell1, long DeCrement1,
		CString IndexCell2, long DeCrement2, CString IndexCell3, long DeCrement3);
	void Sort3(UINT StartX, UINT StartY, UINT EndX, UINT EndY,
		UINT IndexCell1X, UINT IndexCell1Y, long DeCrement1,
		UINT IndexCell2X, UINT IndexCell2Y, long DeCrement2,
		UINT IndexCell3X, UINT IndexCell3Y, long DeCrement3);

	void DrawChart(CString StartCell, CString EndCell, long ChartType, short PlotBy, 
		short StartFrom, CString TitleString, CString X_String, CString Y_String,
		UINT ChartStartX, UINT ChartStartY, UINT width, UINT height); // �e���
	void DrawChart(UINT StartX, UINT StartY, UINT EndX, UINT EndY, long ChartType, short PlotBy, 
		short StartFrom, CString TitleString, CString X_String, CString Y_String,
		UINT ChartStartX, UINT ChartStartY, UINT width, UINT height); // �e���
	void SaveChart(CString FullBmpPathName);

	void SaveAs(CString FullPathName); // �t�s�s��
	void Save(); // �x�s�ɮ�
	void CloseExcel(CString FullPathName);	// ���� Excel �ɮ�
	void QuitApp(); // ���� Excel ���ε{��
	void ReleaseApp(); // ����귽
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// private function

//=====================================================================================
// �N�Ʀr�ର Cell �Ҧ� ex: 314 -> LB
//=====================================================================================

void CExcel::UINT2Cell(UINT StartX, UINT StartY, UINT EndX, UINT EndY, CString &StartCell, CString &EndCell)
{
	char x1[10]; // StartX
	char x2[10]; // EndX
	int index=0;
	int rem=0;

	// cal x1
	memset(x1,0,10);
	index=0;
	do{
		rem = StartX%26, StartX = StartX/26;
		x1[index++] = rem + 'A' -1;
	}while(StartX!=0);
	x1[index]=0, strrev(x1);
	StartCell.Format("%s%lu",x1,StartY);

	// cal x2
	memset(x2,0,10);
	index=0;
	do{
		rem = EndX%26, EndX = EndX/26;
		x2[index++] = rem + 'A' -1;
	}while(EndX!=0);
	x2[index]=0, strrev(x2);

	EndCell.Format("%s%lu",x2,EndY);		
}

//=====================================================================================
// ���o range(by CString)
//=====================================================================================
void CExcel::GetRange(CString StartCell, CString EndCell)
{
	range = objSheet.GetRange(COleVariant(StartCell), COleVariant(EndCell));
	
}

//=====================================================================================
// ���o range(by UINT), Start From 1
//=====================================================================================
void CExcel::GetRange(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	char x1[10]; // StartX
	char x2[10]; // EndX
	UINT index=0, rem=0;
	CString StartCell, EndCell;

	// cal x1
	memset(x1,0,10);
	index=0;
	do{
		rem = StartX%26, StartX = StartX/26;
		x1[index++] = rem + 'A' -1;
	}while(StartX!=0);
	x1[index]=0, strrev(x1);
	StartCell.Format("%s%lu",x1,StartY);

	// cal x2
	memset(x2,0,10);
	index=0;
	do{
		rem = EndX%26, EndX = EndX/26;
		x2[index++] = rem + 'A' -1;
	}while(EndX!=0);
	x2[index]=0, strrev(x2);
	EndCell.Format("%s%lu",x2,EndY);	
	range = objSheet.GetRange(COleVariant(StartCell), COleVariant(EndCell));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// about application and file

//=====================================================================================
// ��l�� excel ���ε{��, �@�ӵ{���u�����@��
//=====================================================================================

BOOL CExcel::InitializeApp()
{	
	COleException e;
	if(!objApp.CreateDispatch("Excel.Application",&e)) return FALSE;
	return TRUE;	
}


//=====================================================================================
// �}�Ҧs�b�ɮ�
//=====================================================================================

BOOL CExcel::OpenExistFile(CString FullPathName, BOOL VISIBLE)
{
	FILE *fp1=fopen(FullPathName,"rb");
	if(fp1==NULL) return FALSE;

	objApp.SetVisible(VISIBLE);			// �i��
	objApp.SetUserControl(FALSE);		// �i��
	objApp.SetDisplayAlerts(FALSE);		// ��ܴ���
	objApp.SetEnableEvents(FALSE);
	objApp.SetAskToUpdateLinks(FALSE); // �s����s
	objApp.SetEnableAnimations(FALSE); // �ʵe����
	objApp.SetAlertBeforeOverwriting(FALSE); // ���߰��мg	


	// ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** //
	// get workbook

	objBooks = objApp.GetWorkbooks();	
	objBook.AttachDispatch(objBooks.Add(_variant_t(FullPathName))); //�}�Ҥ@�Ӥw�s�b���ɮ�
	
	// ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** //
	// get worksheet

	objSheets = objBook.GetWorksheets();
	objSheet = objSheets.GetItem(COleVariant((short)1)); // �q sheet 1 �}�l //

	return TRUE;
}

//=====================================================================================
// �}�s�ɮ�
//=====================================================================================

void CExcel::OpenNewFile(BOOL VISIBLE)
{
	objApp.SetVisible(VISIBLE);			// �i��
	objApp.SetUserControl(FALSE);		// �i��
	objApp.SetDisplayAlerts(FALSE);		// ��ܴ���
	objApp.SetEnableEvents(FALSE);
	objApp.SetAskToUpdateLinks(FALSE); // �s����s
	objApp.SetEnableAnimations(FALSE); // �ʵe����
	objApp.SetAlertBeforeOverwriting(FALSE); // ���߰��мg	

	objBooks = objApp.GetWorkbooks();
	objBook = objBooks.Add(VOptional);
	//objBook.AttachDispatch(objBooks.Add(_variant_t("C:\\test.xls"))); //�}�Ҥ@�Ӥw�s�b���ɮ�
	objSheets = objBook.GetWorksheets();	
	objSheet = objSheets.GetItem(COleVariant((short)1)); //�qsheet1�}�l

	// ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** //
	// get workbook

	objBooks = objApp.GetWorkbooks();	
	objBook = objBooks.Add(VOptional);	
	
	// ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** //
	// get worksheet

	objSheets = objBook.GetWorksheets();
	objSheet = objSheets.GetItem(COleVariant((short)1)); // �q sheet 1 �}�l //
}

//=====================================================================================
// �t�s�s��
//=====================================================================================

void CExcel::SaveAs(CString FullPathName)
{
	objBook.SaveAs(COleVariant(FullPathName),   VOptional,     
	VOptional,   VOptional,   VOptional,   VOptional,     
	1,VOptional,   covFalse,   VOptional,   VOptional,VOptional);
}

//=====================================================================================
// �x�s�ɮ�
//=====================================================================================

void CExcel::Save()
{
	objBook.Save();	
}

//=====================================================================================
// ���� Excel
//=====================================================================================

void CExcel::CloseExcel(CString FullPathName)
{	
	objBook.Close (VOptional,COleVariant(FullPathName),VOptional);
}

//=====================================================================================
// ���� Excel ���ε{��
//=====================================================================================

void CExcel::QuitApp()
{
	objBooks.Close();  
	objApp.Quit();
}

//=====================================================================================
// ����ҥΨ�귽
//=====================================================================================

void CExcel::ReleaseApp()
{
	// release resource
	range.ReleaseDispatch();
	chartobject.ReleaseDispatch();
	chartobjects.ReleaseDispatch();
	

	xlsChart.ReleaseDispatch();
	objSheet.ReleaseDispatch();
	objSheets.ReleaseDispatch();
	objBook.ReleaseDispatch();
	objBooks.ReleaseDispatch();
	objApp.ReleaseDispatch();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// about column and row

//=====================================================================================
// ���o�_�l�C
//=====================================================================================

long CExcel::GetStartColumn()
{
	Range usedrange;
	usedrange.AttachDispatch(objSheet.GetUsedRange());
	return usedrange.GetColumn();
}

//=====================================================================================
// ���o�_�l��
//=====================================================================================

long CExcel::GetStartRow()
{	
	Range usedrange;
	usedrange.AttachDispatch(objSheet.GetUsedRange());
	return usedrange.GetRow();
}

//=====================================================================================
// ���o�`�C��
//=====================================================================================

long CExcel::GetTotalColumn()
{
	Range usedrange;
	usedrange.AttachDispatch(objSheet.GetUsedRange());
	range.AttachDispatch(usedrange.GetColumns());
	return range.GetCount();
}

//=====================================================================================
// ���o�`���
//=====================================================================================

long CExcel::GetTotalRow()
{
	Range usedrange;
	usedrange.AttachDispatch(objSheet.GetUsedRange());
	range.AttachDispatch(usedrange.GetRows());
	return range.GetCount();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// about sheet

//=====================================================================================
// ���o Sheet �Ӽ�
//=====================================================================================

long CExcel::GetSheetNum()
{
	return (objSheets.GetCount());	
}

//=====================================================================================
// ���J�� nIndex �� Sheet
//=====================================================================================

BOOL CExcel::InsertSheet(long nIndex, CString SheetName)
{
	if(nIndex <=0 || nIndex > objSheets.GetCount()) return FALSE;
	objSheet = objSheets.GetItem(COleVariant(nIndex));
	objSheet.Activate();

	objSheets.Add(VOptional,VOptional,VOptional,VOptional);

	objSheet = objSheets.GetItem(COleVariant(nIndex));
	objSheet.SetName(SheetName);	
	return TRUE;
}



//=====================================================================================
// �R�� Sheet
//=====================================================================================

BOOL CExcel::DelSheetIndex(long nIndex)
{
	if(nIndex <=0 || nIndex > objSheets.GetCount()) return FALSE;
	objSheet = objSheets.GetItem(COleVariant((short)nIndex));
	objSheet.Delete();
	return TRUE;
}

//=====================================================================================
// �]�w Sheet Name
//=====================================================================================

BOOL CExcel::SetSheetName(long nIndex, CString SheetName)
{
	if(nIndex <=0 || nIndex > objSheets.GetCount()) return FALSE;
	objSheet = objSheets.GetItem(COleVariant((short)nIndex));
	objSheet.SetName(SheetName);
	return TRUE;
}

//=====================================================================================
// �]�w��e Sheet
//=====================================================================================

BOOL CExcel::SetActiveSheet(long nIndex)
{
	if(nIndex <=0 || nIndex > objSheets.GetCount()) return FALSE;
	objSheet = objSheets.GetItem(COleVariant((short)nIndex));
	objSheet.Activate();
	return TRUE;
}

//=====================================================================================
// ���o SheetName
//=====================================================================================

BOOL CExcel::GetSheetName(long nIndex, CString &SheetName)
{
	if(nIndex<=0 || nIndex > objSheets.GetCount()) return FALSE;
	objSheet = objSheets.GetItem(COleVariant((short)nIndex));
	SheetName = objSheet.GetName();
	return TRUE;
}

//=====================================================================================
// ���o�Ҧ� SheetName
//=====================================================================================
void CExcel::GetSheetName(CString* SheetName)
{		
	long index=0;
	for(index=1; index<=this->GetSheetNum(); index++)
	{		
		objSheet = objSheets.GetItem(COleVariant((short)index));
		SheetName[index-1] = objSheet.GetName();
		
		// CString s1;
		// s1.Format("Sheetname[%ld]=%s",index,SheetName[index-1]);
		// AfxMessageBox(s1,NULL,NULL); 
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//=====================================================================================
// �M���d��
//=====================================================================================
void CExcel::ClearRange(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.Clear();
}

void CExcel::ClearRange(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.Clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// about cell

//=====================================================================================
// �X���x�s��
//=====================================================================================
void CExcel::Merge(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.Merge(_variant_t((short)TRUE));
	
}

void CExcel::Merge(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.Merge(_variant_t((short)TRUE));
}

void CExcel::MergeAll(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetMergeCells(_variant_t((short)TRUE));
}

void CExcel::MergeAll(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetMergeCells(_variant_t((short)TRUE));
}

//=====================================================================================
// ��������覡
//=====================================================================================

void CExcel::SetVertical(CString StartCell,CString EndCell, UINT Alignment) // 1.�W 2.�� 3.�U
{
	this->GetRange(StartCell, EndCell);
	range.SetVerticalAlignment(_variant_t((short)Alignment));
}

void CExcel::SetVertical(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT Alignment) // 1.�W 2.�� 3.�U
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetVerticalAlignment(_variant_t((short)Alignment));
}

void CExcel::SetVerticalUp(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetVerticalAlignment(_variant_t((short)VerticalUp));
}

void CExcel::SetVerticalUp(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetVerticalAlignment(_variant_t((short)VerticalUp));
}

void CExcel::SetVerticalMid(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetVerticalAlignment(_variant_t((short)VerticalCenter));
}

void CExcel::SetVerticalMid(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetVerticalAlignment(_variant_t((short)VerticalCenter));
}

void CExcel::SetVerticalDown(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetVerticalAlignment(_variant_t((short)VerticalDown));
}

void CExcel::SetVerticalDown(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetVerticalAlignment(_variant_t((short)VerticalDown));
}

//=====================================================================================
// ��������覡
//=====================================================================================

void CExcel::SetHorizontal(CString StartCell,CString EndCell, UINT Alignment) // 2.Left 3.Center 4.Right 5.Repeat
{
	this->GetRange(StartCell, EndCell);
	range.SetHorizontalAlignment(_variant_t((short)Alignment));
}

void CExcel::SetHorizontal(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT Alignment)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetHorizontalAlignment(_variant_t((short)Alignment));
}

void CExcel::SetHorizontalLeft(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalLeft));
}

void CExcel::SetHorizontalLeft(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalLeft));
}

void CExcel::SetHorizontalCenter(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalCenter));
}

void CExcel::SetHorizontalCenter(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalCenter));
}

void CExcel::SetHorizontalRight(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalRight));
}

void CExcel::SetHorizontalRight(UINT StartX, UINT StartY, UINT EndX, UINT EndY)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalRight));
}

//=====================================================================================
// �e�ؽu
//=====================================================================================

void CExcel::Border(CString StartCell, CString EndCell, UINT LineStyle, UINT Weight,UINT ColorIndex)
{
	this->GetRange(StartCell, EndCell);
	range.BorderAround(_variant_t((long)LineStyle),Weight,ColorIndex,_variant_t((long)RGB(0,0,0)));
}

void CExcel::Border(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT LineStyle, UINT Weight,UINT ColorIndex)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	range.BorderAround(_variant_t((long)LineStyle),Weight,ColorIndex,_variant_t((long)RGB(0,0,0)));
}

//=====================================================================================
// �]��e
//=====================================================================================

void CExcel::SetWidth(CString StartCell, CString EndCell, float width)
{
	this->GetRange(StartCell, EndCell);
	range.SetColumnWidth(_variant_t(width)); // set width // 
}

void CExcel::SetWidth(UINT Start, UINT End, float width)
{
	this->GetRange(Start, 1, End, 1);
	range.SetColumnWidth(_variant_t(width)); // set width // 	
}

//=====================================================================================
// �]�C��
//=====================================================================================

void CExcel::SetHeight(CString StartCell, CString EndCell, float height)
{
	this->GetRange(StartCell, EndCell);
	range.SetRowHeight(_variant_t(height));
}

void CExcel::SetHeight(UINT Start, UINT End, float height)
{
	this->GetRange(1,Start,1,End);
	range.SetRowHeight(_variant_t(height));
}

//=====================================================================================
// �۰ʽվ���e
//=====================================================================================

void CExcel::AutoSetWidth(CString StartCell, CString EndCell)
{
	this->GetRange(StartCell, EndCell);
	range = range.GetEntireColumn();
	range.AutoFit();
}

void CExcel::AutoSetWidth(UINT Start, UINT End)
{
	this->GetRange(Start, 1, End, 1);
	range = range.GetEntireColumn();
	range.AutoFit();
}

//=====================================================================================
// �]�w FontName(�r��)
//=====================================================================================

void CExcel::SetFontName(CString StartCell, CString EndCell, CString FontName)
{
	this->GetRange(StartCell, EndCell);
	font = range.GetFont();
	font.SetName(_variant_t(FontName));
}

void CExcel::SetFontName(UINT StartX, UINT StartY, UINT EndX, UINT EndY, CString FontName)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	font = range.GetFont();
	font.SetName(_variant_t(FontName));
}

//=====================================================================================
// �]�w FontBold(����)
//=====================================================================================
void CExcel::SetFontBold(CString StartCell, CString EndCell, BOOL BOLD)
{
	this->GetRange(StartCell, EndCell);
	font = range.GetFont();
	font.SetBold(_variant_t((short)BOLD));
}

void CExcel::SetFontBold(UINT StartX, UINT StartY, UINT EndX, UINT EndY, BOOL BOLD)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	font = range.GetFont();
	font.SetBold(_variant_t((short)BOLD));
}

//=====================================================================================
// �]�w FontStrikethorugh(�R���u)
//=====================================================================================
void CExcel::SetFontStrikethrough(CString StartCell, CString EndCell, BOOL STRIKE)
{
	this->GetRange(StartCell, EndCell);
	font = range.GetFont();
	font.SetStrikethrough(_variant_t((short)STRIKE));
}

void CExcel::SetFontStrikethrough(UINT StartX, UINT StartY, UINT EndX, UINT EndY, BOOL STRIKE)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	font = range.GetFont();
	font.SetStrikethrough(_variant_t((short)STRIKE));
}

//=====================================================================================
// �]�w FontSize(�r���j�p)
//=====================================================================================
void CExcel::SetFontSize(CString StartCell, CString EndCell, UINT FontSize)
{
	this->GetRange(StartCell, EndCell);
	font = range.GetFont();
	font.SetSize(_variant_t((short)FontSize));
}

void CExcel::SetFontSize(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT FontSize)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	font = range.GetFont();
	font.SetSize(_variant_t((short)FontSize));
}

//=====================================================================================
// �]�w FontColor(�r���C��^
//=====================================================================================
void CExcel::SetFontColor(CString StartCell, CString EndCell, UINT ColorIndex)
{	
	this->GetRange(StartCell, EndCell);
	font = range.GetFont();
	font.SetColor(_variant_t((short)ColorIndex)); // font color //
}

void CExcel::SetFontColor(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT ColorIndex)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	font = range.GetFont();
	font.SetColor(_variant_t((short)ColorIndex)); // font color //
}

//=====================================================================================
// �]�w FontBkColor(�I����)
//=====================================================================================
void CExcel::SetBkColor(CString StartCell, CString EndCell, UINT ColorIndex)
{
	this->GetRange(StartCell, EndCell);
	cell = range.GetInterior();
	cell.SetColorIndex(_variant_t((short)ColorIndex));	
}

void CExcel::SetBkColor(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT ColorIndex)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	cell = range.GetInterior();
	cell.SetColorIndex(_variant_t((short)ColorIndex));	
}
//=====================================================================================
// �]�w��r�榡
//=====================================================================================

void CExcel::SetFontFormat(CString StartCell, CString EndCell, CString FontName, UINT HorizontalFormat, UINT VerticalFormat,
						   BOOL BOLD, BOOL STRIKE, UINT FontSize, UINT FontColorIndex, UINT BkColorIndex)
{
	this->GetRange(StartCell, EndCell);
	font = range.GetFont();
	cell = range.GetInterior();
	
	range.SetHorizontalAlignment(_variant_t((short)HorizontalFormat));
	range.SetVerticalAlignment(_variant_t((short)VerticalFormat));	

	font.SetName(_variant_t(FontName));
	font.SetBold(_variant_t((short)BOLD));
	font.SetStrikethrough(_variant_t((short)STRIKE));
	font.SetSize(_variant_t((short)FontSize));
	font.SetColorIndex(_variant_t((short)FontColorIndex));
	cell.SetColorIndex(_variant_t((short)BkColorIndex));
}

void CExcel::SetFontFormat(UINT StartX, UINT StartY, UINT EndX, UINT EndY, CString FontName, UINT HorizontalFormat, UINT VerticalFormat,
						   BOOL BOLD, BOOL STRIKE, UINT FontSize, UINT FontColorIndex, UINT BkColorIndex)
{
	this->GetRange(StartX, StartY, EndX, EndY);
	font = range.GetFont();
	cell = range.GetInterior();
	
	range.SetHorizontalAlignment(_variant_t((short)HorizontalFormat));
	range.SetVerticalAlignment(_variant_t((short)VerticalFormat));	

	font.SetName(_variant_t(FontName));
	font.SetBold(_variant_t((short)BOLD));
	font.SetStrikethrough(_variant_t((short)STRIKE));
	font.SetSize(_variant_t((short)FontSize));
	font.SetColorIndex(_variant_t((short)FontColorIndex));
	cell.SetColorIndex(_variant_t((short)BkColorIndex));
}

//=====================================================================================
// �]�w��r
//=====================================================================================
void CExcel::SetText(CString Cell, CString Text)
{
	this->GetRange(Cell,Cell);
	range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(Text));
}

void CExcel::SetText(UINT X, UINT Y, CString Text)
{
	this->GetRange(X,Y,X,Y);
	range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(Text));
}

//=====================================================================================
// �]�w��r�ή榡
//=====================================================================================


void CExcel::SetCellTextFormat(CString Cell, CString FontName,UINT HorizontalFormat, UINT VerticalFormat,
							   BOOL BOLD, BOOL STRIKE, UINT FontSize, UINT FontColorIndex, UINT BkColorIndex,CString Text)
{
	this->GetRange(Cell,Cell);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalFormat));
	range.SetVerticalAlignment(_variant_t((short)VerticalFormat));
	font = range.GetFont();
	cell = range.GetInterior();


	font.SetName(_variant_t(FontName));	
	font.SetBold(_variant_t((short)BOLD));
	font.SetStrikethrough(_variant_t((short)STRIKE));
	font.SetSize(_variant_t((short)FontSize));
	font.SetColorIndex(_variant_t((short)FontColorIndex));
	cell.SetColorIndex(_variant_t((short)BkColorIndex));
	range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(Text));
}


void CExcel::SetCellTextFormat(UINT X, UINT Y,CString FontName,UINT HorizontalFormat, UINT VerticalFormat,
							   BOOL BOLD, BOOL STRIKE, UINT FontSize, UINT FontColorIndex, UINT BkColorIndex,CString Text)
{
	this->GetRange(X,Y,X,Y);
	range.SetHorizontalAlignment(_variant_t((short)HorizontalFormat));
	range.SetVerticalAlignment(_variant_t((short)VerticalFormat));
	font = range.GetFont();
	cell = range.GetInterior();


	font.SetName(_variant_t(FontName));	
	font.SetBold(_variant_t((short)BOLD));
	font.SetStrikethrough(_variant_t((short)STRIKE));
	font.SetSize(_variant_t((short)FontSize));
	font.SetColorIndex(_variant_t((short)FontColorIndex));
	cell.SetColorIndex(_variant_t((short)BkColorIndex));
	range.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t(Text));
}
//=====================================================================================
// Ū����r
//=====================================================================================

CString CExcel::ReadAsString(UINT X, UINT Y)
{
	this->GetRange(X, Y, X, Y);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_BSTR);
	return vResult.bstrVal;
}


CString CExcel::ReadAsInteger(UINT X, UINT Y, int& value)
{
	this->GetRange(X, Y, X, Y);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_INT);

	value = vResult.intVal;
	str1.Format("%d",value);
	return str1;
}

CString CExcel::ReadAsDouble(UINT X, UINT Y, double &value)
{
	this->GetRange(X,Y,X,Y);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);
	
	value = vResult.dblVal;
	str1.Format("%lf",value);
	return str1;
}

CString CExcel::ReadAsDateTime(UINT X, UINT Y, SYSTEMTIME &DateTime)
{
	this->GetRange(X,Y,X,Y);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);	

	VariantTimeToSystemTime(vResult.date,&DateTime);
	str1.Format("%4d/%02d/%02d %02d:%02d:%02d",
		DateTime.wYear, DateTime.wMonth,DateTime.wDay,
		DateTime.wHour, DateTime.wMinute, DateTime.wSecond);

	return str1;	
}
CString CExcel::ReadAsDate(UINT X, UINT Y, SYSTEMTIME &Date)
{
	this->GetRange(X, Y,X,Y);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);	
	VariantTimeToSystemTime(vResult.date,&Date);
	str1.Format("%4d/%02d/%02d",
		Date.wYear, Date.wMonth,Date.wDay);
	return str1;	
}

CString CExcel::ReadAsTime(UINT X, UINT Y, SYSTEMTIME &Time)
{
	this->GetRange(X, Y, X, Y);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);

	VariantTimeToSystemTime(vResult.date,&Time);
	str1.Format("%02d:%02d:%02d",		
		Time.wHour, Time.wMinute, Time.wSecond);
	return str1;	
}

/*
CString CExcel::ReadAsString(CString Cell)
{
	this->GetRange(Cell, Cell);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_BSTR);
	return vResult.bstrVal;
}

CString CExcel::ReadAsInteger(CString Cell, int& value)
{
	this->GetRange(Cell, Cell);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_INT);

	value = vResult.intVal;
	str1.Format("%d",value);
	return str1;
}


CString CExcel::ReadAsDouble(CString Cell,  double &value)
{
	this->GetRange(Cell, Cell);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);
	
	value = vResult.dblVal;
	str1.Format("%lf",value);
	return str1;
}


CString CExcel::ReadAsDateTime(CString Cell, SYSTEMTIME &DateTime)
{
	this->GetRange(Cell, Cell);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);	

	VariantTimeToSystemTime(vResult.date,&DateTime);
	str1.Format("%4d/%02d/%02d %02d:%02d:%02d",
		DateTime.wYear, DateTime.wMonth,DateTime.wDay,
		DateTime.wHour, DateTime.wMinute, DateTime.wSecond);

	return str1;	
}


CString CExcel::ReadAsDate(CString Cell, SYSTEMTIME &Date)
{
	this->GetRange(Cell, Cell);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);	
	
	VariantTimeToSystemTime(vResult.date,&Date);
	str1.Format("%4d/%02d/%02d",
		Date.wYear, Date.wMonth,Date.wDay);
	return str1;	
}

CString CExcel::ReadAsTime(CString Cell, SYSTEMTIME &Time)
{
	this->GetRange(Cell, Cell);
	CString str1;
	COleVariant vResult = range.GetValue2();
	vResult.ChangeType(VT_R8);

	VariantTimeToSystemTime(vResult.date,&Time);
	str1.Format("%02d:%02d:%02d",		
		Time.wHour, Time.wMinute, Time.wSecond);
	return str1;	
}

*/
//=====================================================================================
// �e��
//=====================================================================================

void CExcel::DrawChart(CString StartCell, CString EndCell, long ChartType, short PlotBy, 
		short StartFrom, CString TitleString, CString X_String, CString Y_String,
		UINT ChartStartX, UINT ChartStartY, UINT width, UINT height) // �e���
{	
	lpDisp = objSheet.ChartObjects(VOptional);
	chartobjects.AttachDispatch(lpDisp);
	chartobject = chartobjects.Add(ChartStartX, ChartStartY, width, height);

	xlsChart.AttachDispatch(chartobject.GetChart());
	lpDisp = objSheet.GetRange(COleVariant(StartCell), COleVariant(EndCell));
	range.AttachDispatch(lpDisp);

	var.vt = VT_DISPATCH;
	var.pdispVal = lpDisp;
	xlsChart.ChartWizard(var,  // Source.
			COleVariant((short)11),  // fix please, Gallery: 3d Column. 1 or 11
			COleVariant((short)1),   // fix please, Format, use default
			COleVariant((short)PlotBy),   // PlotBy: 1.X  2.Y			
			COleVariant((short)1),   // fix please
            COleVariant((short)StartFrom),   // SeriesLabels. Start X
			COleVariant((short)TRUE),  // HasLegend.
			_variant_t(COleVariant(TitleString)), // Title1
			_variant_t(COleVariant(X_String)), // Title2
			_variant_t(COleVariant(Y_String)), // Title3
			VOptional  // Title4, fail
			);
	xlsChart.SetChartType((long)ChartType);		
}

void CExcel::DrawChart(UINT StartX, UINT StartY, UINT EndX, UINT EndY, long ChartType, short PlotBy, 
		short StartFrom, CString TitleString, CString X_String, CString Y_String,
		UINT ChartStartX, UINT ChartStartY, UINT width, UINT height) // �e���
{	
	CString StartCell;
	CString EndCell;
	UINT2Cell(StartX, StartY, EndX, EndY,StartCell,EndCell);

	lpDisp = objSheet.ChartObjects(VOptional);
	chartobjects.AttachDispatch(lpDisp);
	chartobject = chartobjects.Add(ChartStartX, ChartStartY, width, height);
	xlsChart.AttachDispatch(chartobject.GetChart());
	lpDisp = objSheet.GetRange(COleVariant(StartCell), COleVariant(EndCell));
	range.AttachDispatch(lpDisp);
	var.vt = VT_DISPATCH;
	var.pdispVal = lpDisp;
	xlsChart.ChartWizard(var,  // Source.
			COleVariant((short)11),  // fix please, Gallery: 3d Column. 1 or 11
			COleVariant((short)1),   // fix please, Format, use default
			COleVariant((short)PlotBy),   // PlotBy: 1.X  2.Y			
			COleVariant((short)1),   // fix please
            COleVariant((short)StartFrom),   // SeriesLabels. Start X
			COleVariant((short)TRUE),  // HasLegend.
			_variant_t(COleVariant(TitleString)), // Title1
			_variant_t(COleVariant(X_String)), // Title2
			_variant_t(COleVariant(Y_String)), // Title3
			VOptional  // Title4, fail
			);
	xlsChart.SetChartType((long)ChartType);	
}

//=====================================================================================
// �s��
//=====================================================================================

void CExcel::SaveChart(CString FullBmpPathName)
{
	xlsChart.Export(LPCTSTR(FullBmpPathName),VOptional,VOptional);
}

//=====================================================================================
// �Ƨ� 1
//=====================================================================================

void CExcel::Sort1(CString StartCell, CString EndCell, CString IndexCell,long DeCrement)
{
	this->GetRange(StartCell,EndCell);	
	VARIANT key1;
	V_VT(&key1) = VT_DISPATCH;
	V_DISPATCH(&key1)=objSheet.GetRange(COleVariant(IndexCell),COleVariant(IndexCell));
	
	range.Sort(
		key1, //  key1
		DeCrement, // long Order1, [ 1(�@��) or 2(����) ]
		VOptional, // key2, 
		VOptional, // type, [xlSortLabels, xlSortValues]
		1, // long Order2, [ 1(�@��) or 2(����) ]
		VOptional, // key3
		1, // long Order3, [ 1(�@��) or 2(����) ]
		0, // Header, [0,1 : ���t title 2 : title �@�_��
		VOptional, // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
		_variant_t((short)TRUE), // MatchCase [TRUE���j�p�g��]
		1, // Orientation : [�ƧǤ�V, 1:���C, 2:����)
		1, // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
		1, // DataOption1 �i�� 0 �P 1
		1, // DataOption2 �i�� 0 �P 1
		1  // DataOption3 �i�� 0 �P 1
		);
}

void CExcel::Sort1(UINT StartX, UINT StartY, UINT EndX, UINT EndY, UINT Cell1, UINT Cell2, long DeCrement)
{
	CString IndexCell;
	this->GetRange(StartX, StartY, EndX, EndY);
	UINT2Cell2(Cell1,Cell2,IndexCell);
	
	VARIANT key1;
	V_VT(&key1) = VT_DISPATCH;
	V_DISPATCH(&key1) = objSheet.GetRange(COleVariant(IndexCell),COleVariant(IndexCell));
	
	range.Sort(
		key1, //  key1
		DeCrement, // long Order1, [ 1(�@��) or 2(����) ]
		VOptional, // key2, 
		VOptional, // type, [xlSortLabels, xlSortValues]
		1, // long Order2, [ 1(�@��) or 2(����) ]
		VOptional, // key3              
		1, // long Order3, [ 1(�@��) or 2(����) ]
		0, // Header, [0,1 : ���t title 2 : title �@�_��
		VOptional, // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
		_variant_t((short)TRUE), // MatchCase [TRUE���j�p�g��]
		1, // Orientation : [�ƧǤ�V, 1:���C, 2:����)
		1, // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
		1, // DataOption1 �i�� 0 �P 1
		1, // DataOption2 �i�� 0 �P 1
		1  // DataOption3 �i�� 0 �P 1
		);
}

//=====================================================================================
// �Ƨ� 2
//=====================================================================================

void CExcel::Sort2(CString StartCell, CString EndCell, CString IndexCell1, long DeCrement1, CString IndexCell2, long DeCrement2)
{	
	this->GetRange(StartCell,EndCell);	
	VARIANT key1;
	VARIANT key2;
	V_VT(&key1) = VT_DISPATCH;
	V_VT(&key2) = VT_DISPATCH;
	V_DISPATCH(&key1)=objSheet.GetRange(COleVariant(IndexCell1),COleVariant(IndexCell1));
	V_DISPATCH(&key2)=objSheet.GetRange(COleVariant(IndexCell2),COleVariant(IndexCell2));
	
	range.Sort(
		key1, //  key1
		DeCrement1, // long Order1, [ 1(�@��) or 2(����) ]
		key2, // key2, 
		VOptional, // type, [xlSortLabels, xlSortValues]
		DeCrement2, // long Order2, [ 1(�@��) or 2(����) ]
		VOptional, // key3
		1, // long Order3, [ 1(�@��) or 2(����) ]
		0, // Header, [0,1 : ���t title 2 : title �@�_��
		VOptional, // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
		_variant_t((short)TRUE), // MatchCase [TRUE���j�p�g��]
		1, // Orientation : [�ƧǤ�V, 1:���C, 2:����)
		1, // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
		1, // DataOption1 �i�� 0 �P 1
		1, // DataOption2 �i�� 0 �P 1
		1  // DataOption3 �i�� 0 �P 1
		);
}


void CExcel::Sort2(UINT StartX, UINT StartY, UINT EndX, UINT EndY,
		UINT IndexCell1X, UINT IndexCell1Y, long DeCrement1,
		UINT IndexCell2X, UINT IndexCell2Y, long DeCrement2)
{
	CString IndexCell1, IndexCell2;
	this->GetRange(StartX, StartY, EndX, EndY);
	UINT2Cell2(IndexCell1X,IndexCell1Y,IndexCell1);
	UINT2Cell2(IndexCell2X,IndexCell2Y,IndexCell2);
	
	VARIANT key1;
	VARIANT key2;
	V_VT(&key1) = VT_DISPATCH;
	V_VT(&key2) = VT_DISPATCH;
	V_DISPATCH(&key1) = objSheet.GetRange(COleVariant(IndexCell1),COleVariant(IndexCell1));
	V_DISPATCH(&key2) = objSheet.GetRange(COleVariant(IndexCell2),COleVariant(IndexCell2));
	
	range.Sort(
		key1, //  key1
		DeCrement1, // long Order1, [ 1(�@��) or 2(����) ]
		key2, // key2, 
		VOptional, // type, [xlSortLabels, xlSortValues]
		DeCrement2, // long Order2, [ 1(�@��) or 2(����) ]
		VOptional, // key3              
		1, // long Order3, [ 1(�@��) or 2(����) ]
		0, // Header, [0,1 : ���t title 2 : title �@�_��
		VOptional, // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
		_variant_t((short)TRUE), // MatchCase [TRUE���j�p�g��]
		1, // Orientation : [�ƧǤ�V, 1:���C, 2:����)
		1, // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
		1, // DataOption1 �i�� 0 �P 1
		1, // DataOption2 �i�� 0 �P 1
		1  // DataOption3 �i�� 0 �P 1
		);
}

//=====================================================================================
// �Ƨ� 3
//=====================================================================================


void CExcel::Sort3(CString StartCell, CString EndCell, CString IndexCell1, long DeCrement1, 
				   CString IndexCell2, long DeCrement2, CString IndexCell3, long DeCrement3)
{	
	this->GetRange(StartCell,EndCell);
	VARIANT key1;
	VARIANT key2;
	VARIANT key3;
	V_VT(&key1) = VT_DISPATCH;
	V_VT(&key2) = VT_DISPATCH;
	V_VT(&key3) = VT_DISPATCH;
	V_DISPATCH(&key1)=objSheet.GetRange(COleVariant(IndexCell1),COleVariant(IndexCell1));
	V_DISPATCH(&key2)=objSheet.GetRange(COleVariant(IndexCell2),COleVariant(IndexCell2));
	V_DISPATCH(&key3)=objSheet.GetRange(COleVariant(IndexCell3),COleVariant(IndexCell3));
	
	range.Sort(
		key1, //  key1
		DeCrement1, // long Order1, [ 1(�@��) or 2(����) ]
		key2, // key2, 
		VOptional, // type, [xlSortLabels, xlSortValues]
		DeCrement2, // long Order2, [ 1(�@��) or 2(����) ]
		key3, // key3
		DeCrement3, // long Order3, [ 1(�@��) or 2(����) ]
		0, // Header, [0,1 : ���t title 2 : title �@�_��
		VOptional, // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
		_variant_t((short)TRUE), // MatchCase [TRUE���j�p�g��]
		1, // Orientation : [�ƧǤ�V, 1:���C, 2:����)
		1, // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
		1, // DataOption1 �i�� 0 �P 1
		1, // DataOption2 �i�� 0 �P 1
		1  // DataOption3 �i�� 0 �P 1
		);
}


void CExcel::Sort3(UINT StartX, UINT StartY, UINT EndX, UINT EndY,
		UINT IndexCell1X, UINT IndexCell1Y, long DeCrement1,
		UINT IndexCell2X, UINT IndexCell2Y, long DeCrement2,
		UINT IndexCell3X, UINT IndexCell3Y, long DeCrement3)
{
	CString IndexCell1, IndexCell2, IndexCell3;
	this->GetRange(StartX, StartY, EndX, EndY);
	UINT2Cell2(IndexCell1X,IndexCell1Y,IndexCell1);
	UINT2Cell2(IndexCell2X,IndexCell2Y,IndexCell2);
	UINT2Cell2(IndexCell3X,IndexCell3Y,IndexCell3);
	
	VARIANT key1;
	VARIANT key2;
	VARIANT key3;
	V_VT(&key1) = VT_DISPATCH;
	V_VT(&key2) = VT_DISPATCH;
	V_VT(&key3) = VT_DISPATCH;
	V_DISPATCH(&key1) = objSheet.GetRange(COleVariant(IndexCell1),COleVariant(IndexCell1));
	V_DISPATCH(&key2) = objSheet.GetRange(COleVariant(IndexCell2),COleVariant(IndexCell2));
	V_DISPATCH(&key3) = objSheet.GetRange(COleVariant(IndexCell2),COleVariant(IndexCell3));
	
	range.Sort(
		key1, //  key1
		DeCrement1, // long Order1, [ 1(�@��) or 2(����) ]
		key2, // key2, 
		VOptional, // type, [xlSortLabels, xlSortValues]
		DeCrement2, // long Order2, [ 1(�@��) or 2(����) ]
		key3, // key3              
		DeCrement3, // long Order3, [ 1(�@��) or 2(����) ]
		0, // Header, [0,1 : ���t title 2 : title �@�_��
		VOptional, // OrderCustom [�q1�}�l�A�۩w�q�ƧǶ��ǦC�������޸��A�ٲ��ϥα`�W]
		_variant_t((short)TRUE), // MatchCase [TRUE���j�p�g��]
		1, // Orientation : [�ƧǤ�V, 1:���C, 2:����)
		1, // SortMethod : [1:���r�ź~�y��������, 2:���r�ŵ��e��]
		1, // DataOption1 �i�� 0 �P 1
		1, // DataOption2 �i�� 0 �P 1
		1  // DataOption3 �i�� 0 �P 1
		);	
}
