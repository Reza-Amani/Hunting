#ifndef T_CHART_PANEL_H
#define T_CHART_PANEL_H

//Don't worry about where some of the supporting classes (e.g. tChartCursor etc.) come from.

struct tSize
{
    int width;
    int height;
};

//
// The chart panel is an abstract base class for displaying a chart in a panel.
//
class tChartPanel
{
    public:
        tChartPanel(tBigObject object);
        ~tChartPanel();

        void ResizePanel(int width, int height);

        void DisplayWarningDialog();
        void DisplayErrorDialog();
        float CalculateBorderWidth();

    protected:
        virtual void InitialisePanelWidget() = 0;

        //Assume there are additional (protected) methods that use each of the data members
        //(except m_PanelId) in some way.
        //...

    private:
        int CalculateBorderColor(int color);

    public:
        int m_PanelId;

    private:
        int   m_cl;
        tSize m_Size;

        std::unique_ptr<tChartCursor> m_pChartCursor;
        tChartTouchController* m_pChartTouchController;
        tChartWidget* m_pChartWidget;
};


#endif
