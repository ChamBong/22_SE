#include "class.h"

/*
 *  Function Name : getInput
 *  Parameters    : 1) inputFile (ifstream) ; 입력된 문자가 저장된 파일스트림
 *  Return Type   : string
 *  Description   : 입력파일로부터 문자를 읽음
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
 *  Parameters    : 1) outputFile (ofstream) ; 결과가 저장될 파일스트림
 *                  2) output     (string)   ; 결과 데이터
 *  Return Type   : -
 *  Description   : 전달받은 문자열을 파일스트림에 출력
 */
void UI::setOutput(ofstream &outputFile, string output)
{
    outputFile << output;
}
