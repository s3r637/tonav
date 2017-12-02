//
// Created by Tomas Krejci on 5/3/16.
//

#include "calibration.h"

#include <cctype>
#include <Eigen/Core>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>

#include "exceptions/impossible_exception.h"
#include "exceptions/calibration_file_error.h"
#include "quaternion.h"

namespace tonav {

Calibration::Calibration()
    : body_to_camera_rotation_(Quaternion::identity()) {
}

void Calibration::setCameraFocalLength(const Eigen::Vector2d &focal_length) {
    focal_length_ = focal_length;
}

Eigen::Vector2d Calibration::getCameraFocalLength() const {
    return focal_length_;
}

void Calibration::setCameraOpticalCenter(const Eigen::Vector2d &optical_center) {
    optical_center_ = optical_center;
}

Eigen::Vector2d Calibration::getCameraOpticalCenter() const {
    return optical_center_;
}

void Calibration::setCameraRadialDistortionParams(const Eigen::Vector3d &distortion_params) {
    radial_distortion_ = distortion_params;
}

Eigen::Vector3d Calibration::getCameraRadialDistortionParams() const {
    return radial_distortion_;
}

void Calibration::setCameraTangentialDistortionParams(const Eigen::Vector2d &distortion_params) {
    tangential_distortion_ = distortion_params;
}

Eigen::Vector2d Calibration::getCameraTangentialDistortionParams() const {
    return tangential_distortion_;
}

void Calibration::setCameraDelayTime(double delay_time) {
    camera_delay_time_ = delay_time;
}

double Calibration::getCameraDelayTime() const {
    return camera_delay_time_;
}

void Calibration::setCameraReadoutTime(double readout_time) {
    camera_readout_time_ = readout_time;
}

double Calibration::getCameraReadoutTime() const {
    return camera_readout_time_;
}
    
void Calibration::setImageNoiseVariance(double image_noise_variance) {
    image_noise_variance_ = image_noise_variance;
}

double Calibration::getImageNoiseVariance() const {
    return image_noise_variance_;
}
    
int Calibration::getNumberOfFeaturesToExtract() const {
    return n_features_to_extract_;
}
    
void Calibration::setGyroscopeAccelerationSensitivityMatrix(const Eigen::Matrix3d &gyroscope_acceleration_sensitivity_matrix) {
    gyroscope_acceleration_sensitivity_matrix_ = gyroscope_acceleration_sensitivity_matrix;
}

Eigen::Matrix3d Calibration::getGyroscopeAccelerationSensitivityMatrix() const {
    return gyroscope_acceleration_sensitivity_matrix_;
}
    
void Calibration::setGyroscopeShapeMatrix(const Eigen::Matrix3d &gyroscope_shape_matrix) {
    gyroscope_shape_matrix_ = gyroscope_shape_matrix;
}

Eigen::Matrix3d Calibration::getGyroscopeShapeMatrix() const {
    return gyroscope_shape_matrix_;
}
    
void Calibration::setAccelerometerShapeMatrix(const Eigen::Matrix3d &accelerometer_shape_matrix) {
    accelerometer_shape_matrix_ = accelerometer_shape_matrix;
}

Eigen::Matrix3d Calibration::getAccelerometerShapeMatrix() const {
    return accelerometer_shape_matrix_;
}
    
void Calibration::setGyroscopeBias(const Eigen::Vector3d &gyroscope_bias) {
    gyroscope_bias_ = gyroscope_bias_;
}

Eigen::Vector3d Calibration::getGyroscopeBias() const {
    return gyroscope_bias_;
}
    
void Calibration::setAccelerometerBias(const Eigen::Vector3d &accelerometer_bias) {
    accelerometer_bias_ = accelerometer_bias;
}

Eigen::Vector3d Calibration::getAccelerometerBias() const {
    return accelerometer_bias_;
}
    
void Calibration::setGlobalGravity(const Eigen::Vector3d &global_gravity) {
    global_gravity_ = global_gravity;
}

Eigen::Vector3d Calibration::getGlobalGravity() const {
    return global_gravity_;
}

void Calibration::setAccelerometerVariance(double accelerometer_variance) {
    accelerometer_variance_ = accelerometer_variance;
}
    
double Calibration::getAccelerometerVariance() const {
    return accelerometer_variance_;
}
    
void Calibration::setGyroscopeVariance(double gyroscope_variance) {
    gyroscope_variance_ = gyroscope_variance;
}

double Calibration::getGyroscopeVariance() const {
    return gyroscope_variance_;
}
    
void Calibration::setAccelerometerRandomWalkVariance(double accelerometer_random_walk_variance) {
    accelerometer_random_walk_variance_ = accelerometer_random_walk_variance;
}

double Calibration::getAccelerometerRandomWalkVariance() const {
    return accelerometer_random_walk_variance_;
}
    
void Calibration::setGyroscopeRandomWalkVariance(double gyroscope_random_walk_variance) {
    gyroscope_random_walk_variance_ = gyroscope_random_walk_variance;
}

double Calibration::getGyroscopeRandomWalkVariance() const {
    return gyroscope_random_walk_variance_;
}
    
void Calibration::setPositionOfBodyInCameraFrameNoise(const Eigen::Vector3d &position_of_body_in_camera_frame_noise) {
    position_of_body_in_camera_frame_noise_ = position_of_body_in_camera_frame_noise;
}

Eigen::Vector3d Calibration::getPositionOfBodyInCameraFrameNoise() const {
    return position_of_body_in_camera_frame_noise_;
}
    
void Calibration::setMaxCameraPoses(int max_camera_poses) {
    max_camera_poses_ = max_camera_poses;
}

int Calibration::getMaxCameraPoses() const {
    return max_camera_poses_;
}
    
void Calibration::setMaxTriangulationIterations(int max_triangulation_iterations) {
    max_triangulation_iterations_ = max_triangulation_iterations;
}

int Calibration::getMaxTriangulationIterations() const {
    return max_triangulation_iterations_;
}
    
void Calibration::setOrientationNoise(const Eigen::Vector3d &orientation_noise) {
    orientation_noise_ = orientation_noise;
}

Eigen::Vector3d Calibration::getOrientationNoise() const {
    return orientation_noise_;
}
    
void Calibration::setPositionNoise(const Eigen::Vector3d &position_noise) {
    position_noise_ = position_noise;
}

Eigen::Vector3d Calibration::getPositionNoise() const {
    return position_noise_;
}
    
void Calibration::setVelocityNoise(const Eigen::Vector3d &velocity_noise) {
    velocity_noise_ = velocity_noise;
}

Eigen::Vector3d Calibration::getVelocityNoise() const {
    return velocity_noise_;
}
    
void Calibration::setGyroscopeBiasNoise(const Eigen::Vector3d &gyroscope_bias_noise) {
    gyroscope_bias_noise_ = gyroscope_bias_noise;
}

Eigen::Vector3d Calibration::getGyroscopeBiasNoise() const {
    return gyroscope_bias_noise_;
}
    
void Calibration::setAccelerometerBiasNoise(const Eigen::Vector3d &accelerometer_bias_noise) {
    accelerometer_bias_noise_ = accelerometer_bias_noise;
}

Eigen::Vector3d Calibration::getAccelerometerBiasNoise() const {
    return accelerometer_bias_noise_;
}
    
void Calibration::setGyroscopeAccelerationSensitivityMatrixNoise(const Eigen::Matrix3d &gyroscope_acceleration_sensitivity_matrix_noise) {
    gyroscope_acceleration_sensitivity_matrix_noise_ = gyroscope_acceleration_sensitivity_matrix_noise;
}

Eigen::Matrix3d Calibration::getGyroscopeAccelerationSensitivityMatrixNoise() const {
    return gyroscope_acceleration_sensitivity_matrix_noise_;
}

void Calibration::setGyroscopeShapeMatrixNoise(const Eigen::Matrix3d &gyroscope_shape_matrix_noise) {
    gyroscope_shape_matrix_noise_ = gyroscope_shape_matrix_noise;
}
    
Eigen::Matrix3d Calibration::getGyroscopeShapeMatrixNoise() const {
    return gyroscope_shape_matrix_noise_;
}
    
void Calibration::setAccelerometerShapeMatrixNoise(const Eigen::Matrix3d &accelerometer_shape_matrix_noise) {
    accelerometer_shape_matrix_noise_ = accelerometer_shape_matrix_noise;
}

Eigen::Matrix3d Calibration::getAccelerometerShapeMatrixNoise() const {
    return accelerometer_shape_matrix_noise_;
}
    
void Calibration::setFocalLengthNoise(const Eigen::Vector2d &focal_length_noise) {
    focal_length_noise_ = focal_length_noise;
}

Eigen::Vector2d Calibration::getFocalLengthNoise() const {
    return focal_length_noise_;
}
    
void Calibration::setOpticalCenterNoise(const Eigen::Vector2d &optical_center_noise) {
    optical_center_noise_ = optical_center_noise;
}

Eigen::Vector2d Calibration::getOpticalCenterNoise() const {
    return optical_center_noise_;
}
    
void Calibration::setRadialDistortionNoise(const Eigen::Vector3d &radial_distortion_noise) {
    radial_distortion_noise_ = radial_distortion_noise;
}

Eigen::Vector3d Calibration::getRadialDistortionNoise() const {
    return radial_distortion_noise_;
}
    
void Calibration::setTangentialDistortionNoise(const Eigen::Vector2d &tangential_distortion_noise) {
    tangential_distortion_noise_ = tangential_distortion_noise;
}

Eigen::Vector2d Calibration::getTangentialDistortionNoise() const {
    return tangential_distortion_noise_;
}
    
void Calibration::setCameraDelayTimeNoise(double camera_delay_time_noise) {
    camera_delay_time_noise_ = camera_delay_time_noise;
}

double Calibration::getCameraDelayTimeNoise() const {
    return camera_delay_time_noise_;
}
    
void Calibration::setCameraReadoutTimeNoise(double camera_readout_time_noise) {
    camera_readout_time_noise_ = camera_readout_time_noise;
}

double Calibration::getCameraReadoutTimeNoise() const {
    return camera_readout_time_noise_;
}

void Calibration::setBodyToCameraRotation(const Quaternion &rotation) {
    body_to_camera_rotation_ = rotation;
}

Quaternion Calibration::getBodyToCameraRotation() const {
    return body_to_camera_rotation_;
}

const std::vector<std::string> Calibration::allowed_params_ = {
    "Camera.focalLength", "Camera.opticalCenter",
    "Camera.radialDistortion", "Camera.tangentialDistortion",
    "Camera.cameraDelayTime", "Camera.cameraReadoutTime",
    "Camera.imageNoiseVariance",
    "ORBextractor.nFeatures",
    "Imu.Ts", "Imu.Tg", "Imu.Ta", "Imu.gyroscopeBias", "Imu.accelerometerBias", "Imu.globalGravity",
    "Imu.accelerometerVariance", "Imu.gyroscopeVariance",
    "Imu.accelerometerRandomWalkVariance", "Imu.gyroscopeRandomWalkVariance",
    "Filter.maxCameraPoses", "Filter.maxTriangulationIterations",
    "Noise.orientation", "Noise.position", "Noise.velocity",
    "Noise.gyroscopeBias", "Noise.accelerometerBias",
    "Noise.Ts", "Noise.Tg", "Noise.Ta",
    "Noise.positionOfBodyInCameraFrame",
    "Noise.focalLength", "Noise.opticalCenter",
    "Noise.radialDistortion", "Noise.tangentialDistortion",
    "Noise.cameraDelayTime", "Noise.cameraReadoutTime"
};

std::shared_ptr<Calibration> Calibration::fromPath(std::string fname) {
    std::shared_ptr<Calibration> calib = std::make_shared<Calibration>();
    
    std::ifstream file(fname.c_str());
    if (!file) {
        throw std::runtime_error("Failed to open configuration file.");
    }
    
    int line_counter = 1;
    std::string line;
    std::map<std::string, std::string> params;
    std::map<std::string, int> param_loc;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            line_counter += 1;
            continue;
        }
        
        std::size_t delim_pos = line.find_first_of(":");
        if (delim_pos == std::string::npos) {
            throw CalibrationFileError(line_counter, "Missing delimiter.");
        }
        
        std::string key = line.substr(0, delim_pos);
        std::string value = line.substr(delim_pos + 1, std::string::npos);
        if (params.find(key) != std::end(params)) {
            throw CalibrationFileError(line_counter, "Value already set.");
        }
        if (std::find(std::begin(allowed_params_), std::end(allowed_params_), key) == std::end(allowed_params_)) {
            throw CalibrationFileError(line_counter, "Unknown parameter '" + key + "'.");
        }
        params[key] = value;
        param_loc[key] = line_counter;
        line_counter += 1;
    }
    for (const std::string &allowed_param : allowed_params_) {
        if (params.find(allowed_param) == std::end(params)) {
            throw CalibrationFileError("Parameter " + allowed_param + " not set in configuration file.");
        }
    }
    
    for (const std::pair<const std::string, std::string> &item : params) {
        std::string key = item.first;
        std::string value = item.second;
        if (key == "Camera.focalLength") {
            if (!Calibration::tryParseVector2d(value, calib->focal_length_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Camera.opticalCenter") {
            if (!Calibration::tryParseVector2d(value, calib->optical_center_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Camera.radialDistortion") {
            if (!Calibration::tryParseVector3d(value, calib->radial_distortion_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Camera.tangentialDistortion") {
            if (!Calibration::tryParseVector2d(value, calib->tangential_distortion_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Camera.cameraDelayTime") {
            if (!Calibration::tryParseDouble(value, calib->camera_delay_time_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Camera.cameraReadoutTime") {
            if (!Calibration::tryParseDouble(value, calib->camera_readout_time_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Camera.imageNoiseVariance") {
            if (!Calibration::tryParseDouble(value, calib->image_noise_variance_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "ORBextractor.nFeatures") {
            if (!Calibration::tryParseInt(value, calib->n_features_to_extract_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.Ts") {
            if (!Calibration::tryParseMatrix3d(value, calib->gyroscope_acceleration_sensitivity_matrix_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.Tg") {
            if (!Calibration::tryParseMatrix3d(value, calib->gyroscope_shape_matrix_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.Ta") {
            if (!Calibration::tryParseMatrix3d(value, calib->accelerometer_shape_matrix_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.gyroscopeBias") {
            if (!Calibration::tryParseVector3d(value, calib->gyroscope_bias_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.accelerometerBias") {
            if (!Calibration::tryParseVector3d(value, calib->accelerometer_bias_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.globalGravity") {
            if (!Calibration::tryParseVector3d(value, calib->global_gravity_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.accelerometerVariance") {
            if (!Calibration::tryParseDouble(value, calib->accelerometer_variance_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.gyroscopeVariance") {
            if (!Calibration::tryParseDouble(value, calib->gyroscope_variance_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.accelerometerRandomWalkVariance") {
            if (!Calibration::tryParseDouble(value, calib->accelerometer_random_walk_variance_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Imu.gyroscopeRandomWalkVariance") {
            if (!Calibration::tryParseDouble(value, calib->gyroscope_random_walk_variance_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Filter.maxCameraPoses") {
            if (!Calibration::tryParseInt(value, calib->max_camera_poses_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Filter.maxTriangulationIterations") {
            if (!Calibration::tryParseInt(value, calib->max_triangulation_iterations_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.orientation") {
            if (!Calibration::tryParseVector3d(value, calib->orientation_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.position") {
            if (!Calibration::tryParseVector3d(value, calib->position_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.velocity") {
            if (!Calibration::tryParseVector3d(value, calib->velocity_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.gyroscopeBias") {
            if (!Calibration::tryParseVector3d(value, calib->gyroscope_bias_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.accelerometerBias") {
            if (!Calibration::tryParseVector3d(value, calib->accelerometer_bias_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.Ts") {
            if (!Calibration::tryParseMatrix3d(value, calib->gyroscope_acceleration_sensitivity_matrix_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.Tg") {
            if (!Calibration::tryParseMatrix3d(value, calib->gyroscope_shape_matrix_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.Ta") {
            if (!Calibration::tryParseMatrix3d(value, calib->accelerometer_shape_matrix_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.positionOfBodyInCameraFrame") {
            if (!Calibration::tryParseVector3d(value, calib->position_of_body_in_camera_frame_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.focalPoint") {
            if (!Calibration::tryParseVector2d(value, calib->focal_length_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.opticalCenter") {
            if (!Calibration::tryParseVector2d(value, calib->optical_center_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.radialDistortion") {
            if (!Calibration::tryParseVector3d(value, calib->radial_distortion_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.tangentialDistortion") {
            if (!Calibration::tryParseVector2d(value, calib->tangential_distortion_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.cameraDelayTime") {
            if (!Calibration::tryParseDouble(value, calib->camera_delay_time_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else if (key == "Noise.cameraReadoutTime") {
            if (!Calibration::tryParseDouble(value, calib->camera_readout_time_noise_)) {
                throw CalibrationFileError(param_loc[key], "Unable to parse value.");
            }
        } else {
            throw ImpossibleException("Non-exhaustive enumeration in camera calibration loading.");
        }
    }
    
    return calib;
}

bool Calibration::tryParseDouble(const std::string &value, double &out) {
    try {
        std::size_t end = 0;
        out = std::stod(value, &end);
        for (std::size_t pos = end; pos < value.size(); ++pos) {
            if (!std::isspace(value[pos])) {
                return false;
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool Calibration::tryParseInt(const std::string &value, int &out) {
    try {
        std::size_t end = 0;
        out = std::stoi(value, &end);
        for (std::size_t pos = end; pos < value.size(); ++pos) {
            if (!std::isspace(value[pos])) {
                return false;
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool Calibration::tryParseVector2d(const std::string &value, Eigen::Vector2d &out) {
    enum class Expect {
        OPEN, MAT_ITEM, CLOSE, ONLY_WHITESPACE
    };
    out = Eigen::Vector2d::Zero();
    Expect expect = Expect::OPEN;
    int item_counter = 0;
    for (std::string::const_iterator it = std::begin(value); it != std::end(value); ++it) {
        if (std::isspace(*it)) {
            continue;
        }
        switch (expect) {
            case Expect::OPEN:
                if (*it != '[')
                    return false;
                expect = Expect::MAT_ITEM;
                break;
            case Expect::MAT_ITEM:
                try {
                    std::size_t after_pos = 0;
                    double item_parsed = stod(std::string(it, std::end(value)), &after_pos);
                    out(item_counter) = item_parsed;
                    it += after_pos - 1;
                    item_counter += 1;
                } catch (...) {
                    return false;
                }
                if (item_counter == 2) {
                    expect = Expect::CLOSE;
                }
                break;
            case Expect::CLOSE:
                if (*it != ']')
                    return false;
                expect = Expect::ONLY_WHITESPACE;
                break;
            case Expect::ONLY_WHITESPACE:
                return false;
                break;
            default:
                throw ImpossibleException("Calibration::tryParseMatrix3d: Non-comprehensive switch statement.");
                break;
        }
    }
    
    return true;
}

bool Calibration::tryParseVector3d(const std::string &value, Eigen::Vector3d &out) {
    enum class Expect {
        OPEN, MAT_ITEM, CLOSE, ONLY_WHITESPACE
    };
    out = Eigen::Vector3d::Zero();
    Expect expect = Expect::OPEN;
    int item_counter = 0;
    for (std::string::const_iterator it = std::begin(value); it != std::end(value); ++it) {
        if (std::isspace(*it)) {
            continue;
        }
        switch (expect) {
            case Expect::OPEN:
                if (*it != '[')
                    return false;
                expect = Expect::MAT_ITEM;
                break;
            case Expect::MAT_ITEM:
                try {
                    std::size_t after_pos = 0;
                    double item_parsed = stod(std::string(it, std::end(value)), &after_pos);
                    out(item_counter) = item_parsed;
                    it += after_pos - 1;
                    item_counter += 1;
                } catch (...) {
                    return false;
                }
                if (item_counter == 3) {
                    expect = Expect::CLOSE;
                }
                break;
            case Expect::CLOSE:
                if (*it != ']')
                    return false;
                expect = Expect::ONLY_WHITESPACE;
                break;
            case Expect::ONLY_WHITESPACE:
                return false;
                break;
            default:
                throw ImpossibleException("Calibration::tryParseMatrix3d: Non-comprehensive switch statement.");
                break;
        }
    }
    return true;
}


bool Calibration::tryParseMatrix3d(const std::string &value, Eigen::Matrix3d &out) {
    enum class Expect {
        OPEN, MAT_ITEM, LINE_SEP, CLOSE, ONLY_WHITESPACE
    };
    out = Eigen::Matrix3d::Zero();
    Expect expect = Expect::OPEN;
    int item_counter = 0;
    for (std::string::const_iterator it = std::begin(value); it != std::end(value); ++it) {
        if (std::isspace(*it)) {
            continue;
        }
        switch (expect) {
            case Expect::OPEN:
                if (*it != '[')
                    return false;
                expect = Expect::MAT_ITEM;
                break;
            case Expect::MAT_ITEM:
                try {
                    std::size_t after_pos = 0;
                    double item_parsed = stod(std::string(it, std::end(value)), &after_pos);
                    out(item_counter / 3, item_counter % 3) = item_parsed;
                    it += after_pos - 1;
                    item_counter += 1;
                } catch (...) {
                    return false;
                }
                if (item_counter == 3 || item_counter == 6) {
                    expect = Expect::LINE_SEP;
                } else if (item_counter == 9) {
                    expect = Expect::CLOSE;
                }
                break;
            case Expect::LINE_SEP:
                if (*it != ';')
                    return false;
                expect = item_counter == 9 ? Expect::CLOSE : Expect::MAT_ITEM;
                break;
            case Expect::CLOSE:
                if (*it != ']')
                    return false;
                expect = Expect::ONLY_WHITESPACE;
                break;
            case Expect::ONLY_WHITESPACE:
                return false;
                break;
            default:
                throw ImpossibleException("Calibration::tryParseMatrix3d: Non-comprehensive switch statement.");
                break;
        }
    }
    
    return true;
}

bool Calibration::tryParseString(const std::string &value, std::string &out) {
    out = value;
    return true;
}

}
