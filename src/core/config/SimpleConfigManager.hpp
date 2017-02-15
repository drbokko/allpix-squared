/**
 *  @author Koen Wolters <koen.wolters@cern.ch>
 */

#ifndef ALLPIX_SIMPLE_CONFIG_MANAGER_H
#define ALLPIX_SIMPLE_CONFIG_MANAGER_H

#include <vector>
#include <string>
#include <utility>

#include "Configuration.hpp"

#include <fstream>

#include "ConfigManager.hpp"

namespace allpix{

    class SimpleConfigManager : public ConfigManager{
    public:
        // Constructor and destructors
        SimpleConfigManager() {}
        SimpleConfigManager(std::string file_name);
        ~SimpleConfigManager() {}
        
        // Add file
        void addFile(std::string file_name);
        void removeFiles();
        
        // Reload all configs (clears and rereads)
        void reload();
        
        // Clear all configuration
        void clear();
        
        // Check if configuration section exist
        virtual bool hasConfiguration(std::string name) const;
        virtual int countConfigurations(std::string name) const;
        
        // Return configuration sections by name
        virtual std::vector<Configuration> getConfigurations(std::string name) const;
        
        // Return all configurations with their name
        virtual std::vector<Configuration> getConfigurations() const;
    private:
        std::map<std::string, std::vector<Configuration> > conf_map_;
        std::vector<std::string> file_names_;
        
        void build_config(std::istream&);
    };
}

#endif // ALLPIX_CONFIG_MANAGER_H
