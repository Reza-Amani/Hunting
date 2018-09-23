#ifndef T_CHART_PANEL_H
#define T_CHART_PANEL_H

struct tSize
{
    unsigned int width;
    unsigned int height;
};

enum class tColor
{
	BORDER_COLOR_RED,
	BORDER_COLOR_BLUE,
	BORDER_COLOR_GREEN,
	BORDER_COLOR_PURPLE,
	BORDER_COLOR_BLACK
};

// The chart panel is an abstract base class for displaying a chart in a panel.
class tChartPanel
{
    public:
		int m_PanelId;
		
		tChartPanel(tBigObject & object);
        ~tChartPanel();

		bool ResizePanel(unsigned int width, unsigned int height);

        void DisplayWarningDialog();
        void DisplayErrorDialog();
        unsigned int CalculateBorderWidth();

    protected:
        virtual void InitialisePanelWidget() = 0;

    private:
        int   m_color;
        tSize m_Size;
        std::unique_ptr<tChartCursor> m_pChartCursor;
        tChartTouchController* m_pChartTouchController;
        tChartWidget* m_pChartWidget;
        tColor CalculateBorderColor(int color);
};


#endif
