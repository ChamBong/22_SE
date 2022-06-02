#include "hong_ping.h"

// Initializing Static Attribute
CollectStatisticsUI* CollectStatisticsUI::collectStatisticsUI = nullptr;
CollectStatistics* CollectStatistics::collectStatistics = nullptr;

CollectStatisticsUI* CollectStatisticsUI::getUiInstance()
{
    if(CollectStatisticsUI::collectStatisticsUI == nullptr)
        CollectStatisticsUI::collectStatisticsUI = new CollectStatisticsUI;

    return CollectStatisticsUI::collectStatisticsUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
CollectStatisticsUI::CollectStatisticsUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
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

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
CollectStatistics::CollectStatistics()
{
    collectStatisticsUI = CollectStatisticsUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
CollectStatistics::~CollectStatistics()
{
    delete collectStatistics;
}
