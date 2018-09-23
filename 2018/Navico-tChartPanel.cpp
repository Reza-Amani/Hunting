//No need to worry about #includes

#define BORDER_COLOR_RED    0
#define BORDER_COLOR_BLUE   1
#define BORDER_COLOR_GREEN  2
#define BORDER_COLOR_PURPLE 3
#define BORDER_COLOR_BLACK  4

tChartPanel::tChartPanel(tBigObject object)
{
    m_PanelId = 0;
    m_cl = BORDER_COLOR_RED;

    m_Size(object.getWidth(), object.getHeight());

    m_pChartWidget = new tChartWidget();
    m_pChartTouchController = new tChartTouchController();
    m_pChartCursor.reset( new tChartCursor());
    
    InitialisePanelWidget();
}

tChartPanel::~tChartPanel()
{
    delete m_pChartWidget;
}

int tChartPanel::CalculateBorderColor(int colorValue)
{
    if( colorValue == BORDER_COLOR_RED)
    {
        return BORDER_COLOR_RED;
    }
    else if (colorValue == BORDER_COLOR_BLUE)
    {
        return BORDER_COLOR_BLUE;
    }
    else if (colorValue == BORDER_COLOR_GREEN)
    {
        return BORDER_COLOR_GREEN;
    }
    else if (colorValue == BORDER_COLOR_PURPLE)
    {
        return BORDER_COLOR_PURPLE;
    }
    else
    {
        return BORDER_COLOR_BLACK;
    }
}

void tChartPanel::ResizePanel(int width, int height)
{
    tResizeParams* pParams = new tResizeParams(width, height);
    m_Size.height = pParams->getHeight();
    m_Size.width = pParams->getWidth();
}

void tChartPanel::DisplayWarningDialog()
{
    tWarningDialog dialog;
    dialog.show();
}

void tChartPanel::DisplayErrorDialog()
{
    std::unique_ptr<tErrorDialog> pDialog;
    pDialog->show();
}

float tChartPanel::CalculateBorderWidth()
{
    int borderWidth = (int)(tBorder::Instance()->getBorderWidth());
    borderWidth += 10;

    return (static_cast<float>(borderWidth)) / 2.0f;
}
