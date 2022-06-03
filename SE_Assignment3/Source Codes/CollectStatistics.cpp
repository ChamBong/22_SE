#include "class.h"

// Initializing Static Attribute
CollectStatisticsUI* CollectStatisticsUI::collectStatisticsUI = nullptr;
CollectStatistics* CollectStatistics::collectStatistics = nullptr;

CollectStatisticsUI* CollectStatisticsUI::getUiInstance()
{
    if(CollectStatisticsUI::collectStatisticsUI == nullptr)
        CollectStatisticsUI::collectStatisticsUI = new CollectStatisticsUI;

    return CollectStatisticsUI::collectStatisticsUI;
}

CollectStatisticsUI::CollectStatisticsUI()
{
    // NOP
}

CollectStatisticsUI::~CollectStatisticsUI()
{
    delete CollectStatisticsUI::collectStatisticsUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
CollectStatistics* CollectStatistics::getControlInstance()
{
    if (CollectStatistics::collectStatistics == nullptr)
        CollectStatistics::collectStatistics = new CollectStatistics;

    return CollectStatistics::collectStatistics;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
CollectStatisticsUI* CollectStatistics::getUI()
{
    return collectStatisticsUI;
}

CollectStatistics::CollectStatistics()
{
    collectStatisticsUI = CollectStatisticsUI::getUiInstance();
}

CollectStatistics::~CollectStatistics()
{
    delete collectStatistics;
}
