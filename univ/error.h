// Error.h
// In the file, define the CError class 
// The CError is about the error message,
// Version : 1.0.0
//					First Version
#ifndef ERROR_H
#define ERROR_H

// Error code
#define TXT_ERR_FALSE											TEXT("Program have an error, process will exit.")

#define	S_ERROR_REGISTRY_CANNOT_WRITE							1
#define TXT_ERR_REGISTRY_CANNOT_WRITE							TEXT("Cannot read the Registry.")

#define S_ERROR_REGISTRY_CANNOT_READ							2
#define TXT_ERR_REGISTRY_CANNOT_READ							TEXT("Cannot write the Registry.")

#define S_ERROR_REGISTRY_READ_FAILED							3
#define TXT_ERR_REGISTRY_READ_FAILED							TEXT("Read registry failed. Please check the registry isn't intact.")

#define S_ERROR_CREATE_WINDOW_FAILED							4
#define	TXT_ERR_CREATE_WINDOW_FAILED							TEXT("Create basce window failed.")

#define S_ERROR_CREATE_ENGINE_FAILED							5
#define TXT_ERR_CREATE_ENGINE_FAILED							TEXT("Create game engine failed.")

#define S_ERROR_ENGINE_INIT_FAILED								6
#define TXT_ERR_ENGINE_INIT_FAILED								TEXT("Game engine initialization failed.")

#define S_ERROR_GAME_INIT_FAILED								7
#define TXT_ERR_GAME_INIT_FAILED								TEXT("Game Initialization failed.")

#define S_ERROR_MUTEX_EXIST										8
#define TXT_ERR_MUTEX_EXIST										TEXT("Cannot run two game process, click OK button to exit.")

#define S_ERROR_LOAD_SCRIPT_FILE								9
#define TXT_ERR_LOAD_SCRIPT_FILE								TEXT("Load Script File Error, Please check file is not exist")

#define S_ERROR_PARAM_VALUE										10
#define TXT_ERR_PARAM_VALUE										TEXT("The param value is wrong.")

#define S_ERROR_CREATE_DEVICE									11
#define TXT_ERR_CREATE_DEVICE									TEXT("Create Device failed.")

#define S_ERROR_GET_SWAP_CHAIN_BUFFER							12
#define TXT_ERR_GET_SWAP_CHAIN_BUFFER							TEXT("Get swap chain buffer failed.")

#define S_ERROR_CREATE_RENDER_TARGET_VIEW						13
#define TXT_ERR_CREATE_RENDER_TARGET_VIEW						TEXT("Create Render target view failed.")

#define S_ERROR_OPEN_LOG_FILE									14
#define TXT_ERR_OPEN_LOG_FILE									TEXT("Open log file failed.")

#define	S_ERROR_NO_OPEN_FILE									15
#define	TXT_ERR_NO_OPEN_FILE									TEXT("No Open file. please select one file.")

#define	S_ERROR_CREATE_OBJECT									16
#define	TXT_ERR_CREATE_OBJECT									TEXT("Create Object Failed. Please Check System Memory and other hardware.")

#define	S_ERROR_FIND_OBJECT										17
#define	TXT_ERR_FIND_OBJECT										TEXT("Find Object form LinkList Fialed.")

#define	S_ERROR_CREATE_TEXUTE									18
#define	TXT_ERR_CREATE_TEXUTE									TEXT("Create Texture Failed.")


// Warning Code
#define S_WARNING_FUNCTION_DISABLE								-1
#define TEXT_WARN_FUNCTION_DISABLE								TEXT("Function is disable,Please contace the Administator for help.")


#endif // !ERROR_H
