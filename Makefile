.PHONY: clean All

All:
	@echo "----------Building project:[ SoftwareRender - Debug_Win ]----------"
	@cd "SoftwareRender" && "$(MAKE)" -f  "SoftwareRender.mk"
clean:
	@echo "----------Cleaning project:[ SoftwareRender - Debug_Win ]----------"
	@cd "SoftwareRender" && "$(MAKE)" -f  "SoftwareRender.mk" clean
