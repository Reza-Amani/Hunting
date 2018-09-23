#ifndef T_CHART_PANEL_H
#define T_CHART_PANEL_H

struct tSize
{
    unsigned int width;
    unsigned int height;
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

        //Assume there are additional (protected) methods that use each of the data members
        //(except m_PanelId) in some way.
        //...

    private:
        int CalculateBorderColor(int color);


    private:
        int   m_cl;
        tSize m_Size;

        std::unique_ptr<tChartCursor> m_pChartCursor;
        tChartTouchController* m_pChartTouchController;
        tChartWidget* m_pChartWidget;
};


#endif
