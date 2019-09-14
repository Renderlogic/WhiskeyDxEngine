# The WhiskeyDxEngine :: to Preserve the Veteran Forces.

## Introduction
This is the official WhiskeyDxEngine repository. The initial purpose of this application is to proof-of-concept 
an algorithm in which the author was told repeatedly is impossible to do programmatically. Python, PHP, Visual C#, Java, and, even 
JavaScript would probably be the ideal release quality version of this application 
in day-to-day usage (likely ASP - because the US Government tech standard is retarded) Sorry Microsoft -> Much Love Bill.

Also the language/stack choice was in part made as an insult to the Lansing Community College administration 
who told me I could not do this as it's not possible... so here we will not only do the "impossible" but do so
in the most difficult of development pipelines - and yes the app will be written in parts of Inline Assembly. 
I also chose to forgo commonality of use in this concept because I do not want script kiddies involved -> you 
must REALLY know how to program to partake in the development - thus the GNU pipeline GDB symbols, G++, 
Make etc. 

Our Veterans Deserve The Best and Brightest Minds.

## Project Overview and Problem Set
One Veteran suicide or death due to disease/disablement is one to many. The sad reality is the "22 daily" 
statistic is reality. Coming from first-hand experience as a prior-service 68 Whiskey aka 
Combat Medic/Healthcare-Specialist... the Author of this application and algorithmic process - John McDonnell - 
understands some of the many unnecessary barriers Veterans face when placing disability claims 
for injuries/disease/ailments incurred during their Service. 

As a prior-service Medic whose literally entered data into ALHTA and VistA (weird AltaVista) - John fully 
understands the medical documentation procedure and diagnosis pipeline. The fact is only medically-licensed 
professionals aptly named Doctors can legally Diagnose or Dx. 

The time it takes to evaluate an existing legal diagnosis for the purpose of VA compensation is far too long.
The current process yields results after an estimated 1-5 years or for us compsci nerds @ a Big-O rate of O(N!).
A simple reduction in process speed may potentially prevent a Veteran suicide from financial constraints. Getting
disability compensation delivered at a process pace of O(1) or near instantaneously yields nothing but positive 
results. 

The faster we can accommodate Veterans needs effectively and efficiently the sooner we may just be able to save 
a life or prevent a Veteran suicide. The faster we can compensate the 7% of our population classified as Veterans who are in 
need of disability compensation - the better off we will be overall. The money need not be drawn from taxpayers – a 
new fund can be created as a way to offset the human debt factor of death from war... i.e. a fund or monetary source 
to distribute as needed upon a recognized and diagnosed service-related disease/illness/injury etc. 

## The Solution
* Create a standardized Veteran/Dependent code – this is needed within the code to be able to reference the payment rating. 
IE Veteran Alone = DependentStatusCode = 1; Veteran and Spouse Only; DependentStatusCode = 2; (maybe try to continue with the 
semantics of it as well for calculations derived from the codes).
* Create a FING standardized patient ID format or agree to existing (FHIR) Etc. Agency-wide.
* Practice what the Government Preaches and FOLLOW STANDARDS.
* Keep It Simple Stupid and Try not to Reinvent the Wheel (SINGLE-USE for the Nerds).
* Assess the computing environment.
* Is this system CUDA Capable? If Yes → load CUDA MODULE  (In the initial first run stage a CUDA 
system to run the processing engine on would be ideal for the massive amount of patients the system will need to analyze).
* Is this system multi-cored? (same concept as above – more CPU power faster results) count/threading additional core potential 
for tackling process heavy-operations.
* Create synthetic patient data source (Synthea) i.e. mock (VistA) EHR to run & test against (which the VA uses! for fsakes).
* Import the most current diagnostic codes from the WHO (ICD-X) i.e. ICD-10 (generate restful curl call)
* Aggregate, Import, and, Generate restful 38 CFR C (Probably already exists somewhere)
* Aggregate, Import, and, Cross-reference 38 CFR C with ICD-10 and benefit rate schedules.
* Ideally obtain real patient data and search for and apply the translated results to newly initiated claims.


## Compiling, Installing, and, Running
* Clone the repo: `git clone https://github.com/Renderlogic/WhiskeyDxEngine.git`

* Compile with debug symbols utilizing the following command : `g++ -o WhiskeyDxEngine  main.cpp LinuxSystemUtils.cpp -ggdb`

* Or just download the binary WhiskeyDxEngine and ./ that mofo

![Image of terminal screenshot of WhiskeyDxEngine]
(screenshot.png)


## Usage/System Requirements
* Ideally a Supercomputer such as NVIDIA DGX stations.
* Ideally CUDA capable NVIDIA GPU
* Ideally Multi-cored CPU
* Linux RPM-Variant
* Run Application via chron job weekly and upon user-invocation.
* Run Application via chron job weekly and upon user-invocation.
* Run Application via chron job weekly and upon user-invocation.
* Run Application via chron job weekly and upon user-invocation.
* Run Application via chron job weekly and upon user-invocation.

## Contributing
Please by all means help me develop this application especially if you have a medical development background. 
VistA EHR experienced-developers welcome. 
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
Please make sure to update tests as appropriate.

## License
Copyright (C) 2019 GNU General Public License v3.0 
Renderlogic, Inc,