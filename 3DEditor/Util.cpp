#include "Util.h"


/* Constants */

const glm::mat4 Util::IDENTITY_MATRIX = glm::mat4 { 1.0f };


/* Functions */

float Util::repeat(float val, float _min, float _max) {
	float res = val;

	if (val < _min) {
		res = _max + std::fmodf(val, _max);
	} else if (val > _max) {
		res = _min - std::fmodf(val, _max);
	}

	return res;
}

glm::vec3 Util::repeat(glm::vec3 val, float _min, float _max) {
	val.x = Util::repeat(val.x, _min, _max);
	val.y = Util::repeat(val.y, _min, _max);
	val.z = Util::repeat(val.z, _min, _max);

	return val;
}

glm::vec2 Util::repeat(glm::vec2 val, float _min, float _max) {
	val.x = Util::repeat(val.x, _min, _max);
	val.y = Util::repeat(val.y, _min, _max);

	return val;
}


// maximum combinations = 4'294'967'296
glm::vec4 Util::generateRGBAColorById(uint32_t colorId) {
	char *rgba = reinterpret_cast<char*>(&colorId);
	return glm::vec4 { rgba[0], rgba[1], rgba[2], rgba[3] };
}

void Util::makeListUniqueVec3(std::vector<glm::vec3>* vectors) {
	if (vectors == nullptr || vectors->size() < 2) return;

	auto sortPred = [](const glm::vec3& lhs, const glm::vec3& rhs) -> bool {
		return lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < rhs.z;
	};

	std::sort(vectors->begin(), vectors->end(), sortPred);
	vectors->erase(std::unique(vectors->begin(), vectors->end()), vectors->end());
}


std::string Util::getTextFromFile(const std::filesystem::path& filePath) {
	if (!std::filesystem::exists(filePath)) {
		throw std::exception { (filePath.string() + " isn't exists").c_str() };
	}

	if (std::filesystem::is_directory(filePath)) {
		throw std::exception { (filePath.string() + " isn't file").c_str() };
	}

	std::ifstream fh;

	fh.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::stringstream res {};

	try {
		fh.open(filePath);
		res << fh.rdbuf();
		fh.close();
	} catch (...) {
		throw;
	}

	return res.str();
}
