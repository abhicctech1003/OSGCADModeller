# OSGCADModeller

Open Scene Graph(OSG) Based CAD Modeller to render primitive shapes. 

## Getting Started

- This C++ project have the features, such as drag-and-drop functionality for adding primitive shapes, navigation controls for viewing the model.
- The graphics rendering component utilizes the Open Scene Graph (OSG) library. 
- It handles the creation and rendering of the 3D scene, including all the primitive shapes added by the user. 
- It allows users to add and remove shapes.

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/abhicctech1003/OSGCADModeller.git
    ```

2. **Build the Project:**

    Open the project in your preferred C++ IDE or build using the command line.

3. **Run the Application:**

    Execute the built binary to run the application.


## Folder Structure
The project is organized into the following folders:

- **headers**: Contains header files for OpenSceneGraphViewer, Primitives, Visualizer class.
 
- **src**: Contains implementation files corresponding to each header file.

- **main.cpp**: Main source file where the program execution starts.


## Primitives Class

- Primitives class provide the methods for primitive creation to be rendered.


## OpenSceneGraphViewer Class

- OpenSceneGraphViewer class contains the implementation of creation open scene graph based viewer to render primitives.
- It also contains events related to mouse.


## Visualizer Class

- Visualizer class contains all user interface related part of QT, also contains plane selection functionality for rendering.
- It also contains implentation of all functionality related to buttons.


## Additional Notes

- Make sure to provide the correct file paths and ensure that the input files are in the appropriate format for successful conversion.
- Check the console output for any error messages or status updates during the conversion process.

## Implementation Details

- Language and Environment: Implemented in Visual Studio using C++.
- Open Scene Graph toolkit.
- Qt.

## Requirements
- Visual Studio
- Knowledge of C# programming language
- Implementation knowledge of Qt 
- Understanding of Open Scene Graph toolkit and OSG file formats
