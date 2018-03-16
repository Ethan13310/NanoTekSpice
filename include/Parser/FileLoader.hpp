/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
**         FileLoader.hpp
*/

#pragma once

#include <sstream>
#include <string>

namespace nts
{
	class FileLoader
	{
	public:
		explicit FileLoader(std::string const &filepath);
		~FileLoader() = default;

		FileLoader(FileLoader const &) = delete;
		FileLoader(FileLoader &&) = default;

		FileLoader& operator=(FileLoader const &) = delete;
		FileLoader& operator=(FileLoader &&) = default;

		bool nextLine(std::string &line);
		void reset();

	private:
		std::string m_data;
		std::stringstream m_stream;
	};
}
