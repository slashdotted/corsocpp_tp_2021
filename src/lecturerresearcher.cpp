#include "lecturerresearcher.h"

LecturerResearcher::LecturerResearcher(const std::string& name,
                    const std::string& institute,
                    int nr,
                    const std::string& studies,
                    const std::string& course,
                    const std::string& researcharea,
                    double researchpercentage)
                    : Employee{name, institute, nr}, 
                    Lecturer{name, institute, nr, studies, course}, 
                    Researcher{name, institute, nr, researcharea},
                    m_researchpercentage{researchpercentage} {}

double LecturerResearcher::researchpercentage() const {
    return m_researchpercentage;
}

std::string LecturerResearcher::classname() const {
    return"LecturerResearcher";
}