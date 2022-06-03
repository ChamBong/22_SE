#include "class.h"

/*
 *  Function Name : 
 *  Parameters    : 
 *  Return Type   : 
 *  Description   : 
 */
string UI::getInput(ifstream &inputFile)
{
    string inputString;
    getline(inputFile, inputString, ' ');  // Blank Compaction
    getline(inputFile, inputString, '\n');
    return inputString;
}

/*
 *  Function Name : setOutput
 *  Parameters    : 1) outputFile (ofstream) ; ����� ����� ���Ͻ�Ʈ��
 *                  2) output     (string)   ; ��� ������
 *  Return Type   : -
 *  Description   : ���޹��� ���ڿ��� ���Ͻ�Ʈ���� ���
 */
void UI::setOutput(ofstream &outputFile, string output)
{
    outputFile << output;
}