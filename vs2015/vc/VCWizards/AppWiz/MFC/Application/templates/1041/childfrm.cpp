[!if RIBBON_TOOLBAR]
// ���� MFC �T���v�� �\�[�X �R�[�h�ł́AMFC Microsoft Office Fluent ���[�U�[ �C���^�[�t�F�C�X 
// ("Fluent UI") �̎g�p���@�������܂��B���̃R�[�h�́AMFC C++ ���C�u���� �\�t�g�E�F�A�� 
// ��������Ă��� Microsoft Foundation Class ���t�@�����X����ъ֘A�d�q�h�L�������g��
// �⊮���邽�߂̎Q�l�����Ƃ��Ē񋟂���܂��B
// Fluent UI �𕡐��A�g�p�A�܂��͔z�z���邽�߂̃��C�Z���X�����͌ʂɗp�ӂ���Ă��܂��B
// Fluent UI ���C�Z���X �v���O�����̏ڍׂɂ��ẮAWeb �T�C�g
// http://go.microsoft.com/fwlink/?LinkId=238214 ���Q�Ƃ��Ă��������B
//
// Copyright (C) Microsoft Corporation
// All rights reserved.
[!endif]

// [!output CHILD_FRAME_IMPL] : [!output CHILD_FRAME_CLASS] �N���X�̎���
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

#include "[!output CHILD_FRAME_HEADER]"
[!if PROJECT_STYLE_EXPLORER]
#include "[!output TREE_VIEW_HEADER]"
#include "[!output VIEW_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// [!output CHILD_FRAME_CLASS]

IMPLEMENT_DYNCREATE([!output CHILD_FRAME_CLASS], [!output CHILD_FRAME_BASE_CLASS])

BEGIN_MESSAGE_MAP([!output CHILD_FRAME_CLASS], [!output CHILD_FRAME_BASE_CLASS])
[!if !DOCVIEW]
	ON_COMMAND(ID_FILE_CLOSE, &[!output CHILD_FRAME_CLASS]::OnFileClose)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
	ON_UPDATE_COMMAND_UI_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, &[!output CHILD_FRAME_CLASS]::OnUpdateViewStyles)
	ON_COMMAND_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, &[!output CHILD_FRAME_CLASS]::OnViewStyle)
[!endif]
[!endif]
[!if PRINTING]
[!if RIBBON_TOOLBAR]
	ON_COMMAND(ID_FILE_PRINT, &[!output CHILD_FRAME_CLASS]::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &[!output CHILD_FRAME_CLASS]::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &[!output CHILD_FRAME_CLASS]::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &[!output CHILD_FRAME_CLASS]::OnUpdateFilePrintPreview)
[!endif]
[!endif]
END_MESSAGE_MAP()

// [!output CHILD_FRAME_CLASS] �R���X�g���N�V����/�f�X�g���N�V����

[!output CHILD_FRAME_CLASS]::[!output CHILD_FRAME_CLASS]()
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
	// TODO: �����o�[�������R�[�h�������ɒǉ����Ă��������B
}

[!output CHILD_FRAME_CLASS]::~[!output CHILD_FRAME_CLASS]()
{
}

[!if APP_TYPE_MDI && SPLITTER]
BOOL [!output CHILD_FRAME_CLASS]::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
[!if PROJECT_STYLE_EXPLORER]
	// �����E�B���h�E�̍쐬
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS([!output TREE_VIEW_CLASS]), CSize(100, 100), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS([!output VIEW_CLASS]), CSize(100, 100), pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}
	return TRUE;
[!else]
[!if HTML_VIEW || HTML_EDITVIEW]
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: �s�Ɨ�̐��𒲐����Ă��������B
		CSize(10, 10),	// TODO: �ŏ��y�C���̃T�C�Y��ύX���܂��B
		pContext, WS_CHILD | WS_VISIBLE | SPLS_DYNAMIC_SPLIT);
[!else]
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: �s�Ɨ�̐��𒲐����Ă��������B
		CSize(10, 10),	// TODO: �ŏ��y�C���̃T�C�Y��ύX���܂��B
		pContext);
[!endif]
[!endif]
}
[!else]
[!if PROJECT_STYLE_EXPLORER]
BOOL [!output CHILD_FRAME_CLASS]::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	// �����E�B���h�E�̍쐬
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS([!output TREE_VIEW_CLASS]), CSize(100, 100), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS([!output VIEW_CLASS]), CSize(100, 100), pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}
	return TRUE;
}
[!endif]
[!endif]

BOOL [!output CHILD_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs ��ύX���āAWindow �N���X�܂��̓X�^�C����ύX���܂��B
	if( ![!output CHILD_FRAME_BASE_CLASS]::PreCreateWindow(cs) )
		return FALSE;

[!if !CHILD_FRAME_DEFAULT_STYLES]
	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE[!output CHILD_FRAME_STYLE_FLAGS];

[!endif]
[!if !DOCVIEW]
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
[!endif]
	return TRUE;
}

// [!output CHILD_FRAME_CLASS] �f�f

#ifdef _DEBUG
void [!output CHILD_FRAME_CLASS]::AssertValid() const
{
	[!output CHILD_FRAME_BASE_CLASS]::AssertValid();
}

void [!output CHILD_FRAME_CLASS]::Dump(CDumpContext& dc) const
{
	[!output CHILD_FRAME_BASE_CLASS]::Dump(dc);
}
#endif //_DEBUG

// [!output CHILD_FRAME_CLASS] ���b�Z�[�W �n���h���[
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
[!output VIEW_CLASS]* [!output CHILD_FRAME_CLASS]::GetRightPane()
{
	CWnd* pWnd = m_wndSplitter.GetPane(0, 1);
	[!output VIEW_CLASS]* pView = DYNAMIC_DOWNCAST([!output VIEW_CLASS], pWnd);
	return pView;
}

void [!output CHILD_FRAME_CLASS]::OnUpdateViewStyles(CCmdUI* pCmdUI)
{
	if (!pCmdUI)
		return;

	// TODO: [�\��] ���j���[�̑I��������������ɂ́A���̃R�[�h���J�X�^�}�C�Y�܂��͊g�����܂��B
	[!output VIEW_CLASS]* pView = GetRightPane(); 

	// �E���̃y�C�����쐬����Ă��Ȃ����A�r���[�ɂȂ��Ă��Ȃ��ꍇ�́A���͈̔͂̃R�}���h�𖳌��ɂ��܂��B
	if (pView == NULL)
		pCmdUI->Enable(FALSE);
	else
	{
		DWORD dwStyle = pView->GetStyle() & LVS_TYPEMASK;
		// �����R�}���h�� ID_VIEW_LINEUP �Ȃ�΁ALVS_ICON or LVS_SMALLICON
		// ���[�h�ɂȂ����ꍇ�����A���̃R�}���h��L���ɂ��܂�
		if (pCmdUI->m_nID == ID_VIEW_LINEUP)
		{
			if (dwStyle == LVS_ICON || dwStyle == LVS_SMALLICON)
				pCmdUI->Enable();
			else
				pCmdUI->Enable(FALSE);
		}
		else
		{
			// ����ȊO�̏ꍇ�́A�r���[�̃X�^�C���𔽉f�����邽�߂Ƀh�b�g���g���Ă��������B
			pCmdUI->Enable();
			BOOL bChecked = FALSE;

			switch (pCmdUI->m_nID)
			{
			case ID_VIEW_DETAILS:
				bChecked = (dwStyle == LVS_REPORT);
				break;

			case ID_VIEW_SMALLICON:
				bChecked = (dwStyle == LVS_SMALLICON);
				break;

			case ID_VIEW_LARGEICON:
				bChecked = (dwStyle == LVS_ICON);
				break;

			case ID_VIEW_LIST:
				bChecked = (dwStyle == LVS_LIST);
				break;

			default:
				bChecked = FALSE;
				break;
			}

			pCmdUI->SetRadio(bChecked ? 1 : 0);
		}
	}
}

void [!output CHILD_FRAME_CLASS]::OnViewStyle(UINT nCommandID)
{
	// TODO: [�\��] ���j���[�̑I��������������ɂ́A���̃R�[�h���J�X�^�}�C�Y�܂��͊g�����܂��B
	[!output VIEW_CLASS]* pView = GetRightPane();

	// �E���̃y�C�����쐬����Ă��āA[!output VIEW_CLASS] �ł���ꍇ�A���j���[ �R�}���h���������܂�...
	if (pView != NULL)
	{
		int nStyle = -1;

		switch (nCommandID)
		{
		case ID_VIEW_LINEUP:
			{
				// ���X�g �R���g���[���̃A�C�R�����O���b�h�ʒu�ɍ��킹�܂��B
				CListCtrl& refListCtrl = pView->GetListCtrl();
				refListCtrl.Arrange(LVA_SNAPTOGRID);
			}
			break;

		// ���̃R�}���h�̓��X�g �R���g���[���̃X�^�C����ύX���܂��B
		case ID_VIEW_DETAILS:
			nStyle = LVS_REPORT;
			break;

		case ID_VIEW_SMALLICON:
			nStyle = LVS_SMALLICON;
			break;

		case ID_VIEW_LARGEICON:
			nStyle = LVS_ICON;
			break;

		case ID_VIEW_LIST:
			nStyle = LVS_LIST;
			break;
		}

		// �X�^�C���ύX; �E�B���h�E�͎����I�ɍĕ`�悵�܂��B
		if (nStyle != -1)
			pView->ModifyStyle(LVS_TYPEMASK, nStyle);
	}
}
[!endif]
[!endif]
[!if !DOCVIEW]
void [!output CHILD_FRAME_CLASS]::OnFileClose() 
{
	// ���̃t���[�������ɂ́AWM_CLOSE �𑗂�܂��B���̃��b�Z�[�W�́A
	// �V�X�e�� ���j���[�� [����] ��I�������ꍇ�Ɠ����ł��B
	SendMessage(WM_CLOSE);
}

int [!output CHILD_FRAME_CLASS]::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if ([!output CHILD_FRAME_BASE_CLASS]::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// �t���[���̃N���C�A���g�̈�S�̂��߂�r���[���쐬���܂��B
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("�r���[ �E�B���h�E���쐬�ł��܂���ł����B\n");
		return -1;
	}

	return 0;
}

void [!output CHILD_FRAME_CLASS]::OnSetFocus(CWnd* pOldWnd) 
{
	[!output CHILD_FRAME_BASE_CLASS]::OnSetFocus(pOldWnd);

	m_wndView.SetFocus();
}

BOOL [!output CHILD_FRAME_CLASS]::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// �r���[�ɍŏ��ɃR�}���h����������@���^���܂��B
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;
	
	// ����ȊO�̏ꍇ�́A����̏������s���܂��B
	return [!output CHILD_FRAME_BASE_CLASS]::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
[!endif]
[!if PRINTING]
[!if RIBBON_TOOLBAR]

void [!output CHILD_FRAME_CLASS]::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void [!output CHILD_FRAME_CLASS]::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // ����v���r���[ ���[�h�������I�ɏI������
	}
}

void [!output CHILD_FRAME_CLASS]::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}
[!endif]
[!endif]