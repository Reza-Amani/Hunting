//No need to worry about #includes

tChartPanel::tChartPanel(tBigObject const & object, tChartWidget & _m_pChartWidget, tChartTouchController & _m_pChartTouchController)
{
    m_PanelId = 0;
	m_color = tColor::BORDER_COLOR_RED;

	m_Size = { object.getWidth(), object.getHeight() };

	m_pChartWidget = _m_pChartWidget;
	m_pChartTouchController = _m_pChartTouchController;
    m_pChartCursor.reset( new tChartCursor());
    
    //other Initialisations
}

tChartPanel::~tChartPanel()
{
	delete m_pChartCursor;
}

tColor tChartPanel::CalculateBorderColor(int colorValue)
{
	if (colorValue > (int)tColor::BORDER_COLOR_BLACK)
    {
		return BORDER_COLOR_BLACK;
    }
    else
    {
		return (tColor)colorValue;
    }
}

bool tChartPanel::ResizePanel(unsigned int width, unsigned int height)
{
	if (width <= MAX_LENGTH && height <= MAX_LENGTH)
	{
		m_Size = { width, height };
		return true;
	}
	else
	{
		return false;
	}
}

void tChartPanel::DisplayWarningDialog()
{
	tWarningDialog * p_dialog = new tWarningDialog();
	if (p_dialog)
	{
		p_dialog->show();
		delete p_dialog;
	}
}

void tChartPanel::DisplayErrorDialog()
{
    std::unique_ptr<tErrorDialog> pDialog;	//new
    pDialog->show();
}

unsigned int tChartPanel::CalculateBorderWidth(const tBorder & _m_border)
{
	unsigned int borderWidth = _m_border.getBorderWidth();
    borderWidth += 10;

	return borderWidth/2;
}
