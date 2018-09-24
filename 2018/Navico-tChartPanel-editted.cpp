//No need to worry about #includes

tChartPanel::tChartPanel(tBigObject const & object, tChartWidget & _m_pChartWidget, tChartTouchController & _m_pChartTouchController)
{
    m_PanelId = 0;
	m_color = tColor::BORDER_COLOR_RED;

	m_Size = { object.getWidth(), object.getHeight() };

	m_pChartWidget = _m_pChartWidget;
	m_pChartTouchController = _m_pChartTouchController;
	m_pChartCursor.reset(std::unique_ptr<tChartCursor>(new tChartCursor());
    
    //other Initialisations
}

tChartPanel::~tChartPanel()
{
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
	//this function should be moved out of this class, as violates the SRP
	//But, for sake of the test, I refactor and keep it for now
	if (width <= MAX_WIDTH && height <= MAX_HEIGTH)
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
	std::unique_ptr<tWarningDialog> p_dialog(new tWarningDialog());
	if (p_dialog)
	{
		p_dialog->show();
	}
}

void tChartPanel::DisplayErrorDialog()
{
	std::unique_ptr<tErrorDialog> p_dialog(new tErrorDialog());
	if (p_dialog)
	{
		p_dialog->show();
	}
}

unsigned int tChartPanel::CalculateBorderWidth(const tBorder & _m_border)
{
	unsigned int borderWidth = _m_border.getBorderWidth();
    borderWidth += 10;

	return borderWidth/2;
}
