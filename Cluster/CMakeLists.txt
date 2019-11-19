cmake_minimum_required( VERSION 3.5 )

project( Cluster_Cpp )

find_package(OpenCV REQUIRED)

# Library

# Set header files for the library
file(GLOB_RECURSE CURRENT_HEADERS  "*.h" ) 

source_group( CLUSTER FILES  
	DBSCAN.h 
	Estimator.h
	IOoperate.h 
	MeanShift.h)

add_executable( ClusterTest ClusterTest.cpp )