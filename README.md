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

## Output Screenshots
- Point
![01-Point](https://github.com/abhicctech1003/OSGCADModeller/assets/158149347/67d25d72-9200-414e-972e-12739d6f6682)

- Line
![02-Line](https://github.com/abhicctech1003/OSGCADModeller/assets/158149347/ed7bebaa-6347-48d9-a412-4bc2f719e7fd)

-Circle
![03-Circle](https://github.com/abhicctech1003/OSGCADModeller/assets/158149347/15b4f301-f1c7-4c0c-b23d-3257df50e423)

-Ellipse
![04-Ellipse](https://github.com/abhicctech1003/OSGCADModeller/assets/158149347/d517c4e4-5b66-4bbd-98fe-9dd2a11ae32c)

-Arc
![05-Arc](https://github.com/abhicctech1003/OSGCADModeller/assets/158149347/8e7d800e-ba99-49ea-a954-eb69b553d9b5)


